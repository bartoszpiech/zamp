#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <sstream>

using namespace std;

#include "Interp4Command.hh"
#include "MobileObj.hh"
#include "LibInterface.hh"
#include "Set4LibInterfaces.hh"
#include "Vector3D.hh"

// nowe headery xmlinterp
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include "xmlinterp.hh"

using namespace xercesc;
bool ReadFile(const char* sFileName, Configuration &rConfig);

#define LINE_SIZE 500

/*
 * \brief Funkcja wykonująca czynności preprocesora (usuwa komentarze, zamienia
 * #define na konkretne wartości).
 */
bool ExecPreprocessor(const char *fileName, istringstream &iStrm4Cmds) {
	string cmd4Preproc = "cpp -P ";
	char line[LINE_SIZE];
	ostringstream oTmpStrm;
	cmd4Preproc += fileName;
	FILE *pProc = popen(cmd4Preproc.c_str(), "r");
	if (!pProc) {
		return false;
	}
	while (fgets(line, LINE_SIZE, pProc)) {
		oTmpStrm << line;
	}
	iStrm4Cmds.str(oTmpStrm.str());
	return pclose(pProc) == 0;
}

int main(int argc, char **argv) {
	// sprawdzenie ilosci argumentow przy wywolaniu programu
	if (argc == 2) {
		istringstream stream;
		if (!ExecPreprocessor(argv[1],stream)) {
			cerr << "!!! Wywolanie preprocesora sie nie powiodlo" << endl;
			return 1;
		}
		//cout << stream.str();
		Set4LibInterfaces interfaces;
		interfaces.addInterface("libs/libInterp4Rotate.so");
		interfaces.addInterface("libs/libInterp4Pause.so");
		interfaces.addInterface("libs/libInterp4Set.so");
		interfaces.addInterface("libs/libInterp4Move.so");

		std::string cmd_name;
		while (stream >> cmd_name) {
			if (interfaces.map.find(cmd_name) == interfaces.map.end()) {
				cerr << "Nie znaleziono komendy: " << cmd_name << endl;
				break;
			}
			Interp4Command *pcmd = interfaces.map[cmd_name]->pCreateCmd();
			if (!pcmd->ReadParams(stream)) {
				cerr << "Wczytywanie parametrow nie powiodlo sie" << endl;
			}
			pcmd->PrintCmd();
		}
		Configuration   Config;
		if (!ReadFile("config/config.xml",Config)) return 1;
	}

	/*
	Vector3D vec;
	istringstream txtStream("20 2 4");
	txtStream >> vec;
	cout << vec;
	*/

	/* TEST
	Set4LibInterfaces interfaces;
	interfaces.addInterface("libInterp4Set.so");
	interfaces.addInterface("libInterp4Move.so");
	interfaces.addInterface("libInterp4Rotate.so");
	interfaces.addInterface("libInterp4Pause.so");
	Interp4Command *pCmd_Move = interfaces.map["Move"]->pCreateCmd();
	Interp4Command *pCmd_Set = interfaces.map["Set"]->pCreateCmd();
	Interp4Command *pCmd_Rotate = interfaces.map["Rotate"]->pCreateCmd();
	Interp4Command *pCmd_Pause = interfaces.map["Pause"]->pCreateCmd();

	cout << endl;
	cout << pCmd_Move->GetCmdName() << endl;
	cout << endl;
	cout << pCmd_Set->GetCmdName() << endl;
	cout << endl;
	cout << pCmd_Rotate->GetCmdName() << endl;
	cout << endl;
	cout << pCmd_Pause->GetCmdName() << endl;
	cout << endl;
	pCmd_Move->PrintSyntax();
	cout << endl;
	pCmd_Move->PrintCmd();
	cout << endl;
	pCmd_Set->PrintSyntax();
	cout << endl;
	pCmd_Set->PrintCmd();
	cout << endl;
	pCmd_Rotate->PrintSyntax();
	cout << endl;
	pCmd_Rotate->PrintCmd();
	cout << endl;
	pCmd_Pause->PrintSyntax();
	cout << endl;
	pCmd_Pause->PrintCmd();
	cout << endl;

	delete pCmd_Move;
	delete pCmd_Set;
	delete pCmd_Rotate;
	delete pCmd_Pause;
	*/
}

/*!
 * Czyta z pliku opis poleceń i dodaje je do listy komend,
 * które robot musi wykonać.
 * \param sFileName - (\b we.) nazwa pliku z opisem poleceń.
 * \param CmdList - (\b we.) zarządca listy poleceń dla robota.
 * \retval true - jeśli wczytanie zostało zrealizowane poprawnie,
 * \retval false - w przeciwnym przypadku.
 */
bool ReadFile(const char* sFileName, Configuration &rConfig)
{
   try {
            XMLPlatformUtils::Initialize();
   }
   catch (const XMLException& toCatch) {
            char* message = XMLString::transcode(toCatch.getMessage());
            cerr << "Error during initialization! :\n";
            cerr << "Exception message is: \n"
                 << message << "\n";
            XMLString::release(&message);
            return 1;
   }

   SAX2XMLReader* pParser = XMLReaderFactory::createXMLReader();

   pParser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
   pParser->setFeature(XMLUni::fgSAX2CoreValidation, true);
   pParser->setFeature(XMLUni::fgXercesDynamic, false);
   pParser->setFeature(XMLUni::fgXercesSchema, true);
   pParser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);

   pParser->setFeature(XMLUni::fgXercesValidationErrorAsFatal, true);

   DefaultHandler* pHandler = new XMLInterp4Config(rConfig);
   pParser->setContentHandler(pHandler);
   pParser->setErrorHandler(pHandler);

   try {
     
     if (!pParser->loadGrammar("config/config.xsd",
                              xercesc::Grammar::SchemaGrammarType,true)) {
       cerr << "!!! Plik grammar/actions.xsd, '" << endl
            << "!!! ktory zawiera opis gramatyki, nie moze zostac wczytany."
            << endl;
       return false;
     }
     pParser->setFeature(XMLUni::fgXercesUseCachedGrammarInParse,true);
     pParser->parse(sFileName);
   }
   catch (const XMLException& Exception) {
            char* sMessage = XMLString::transcode(Exception.getMessage());
            cerr << "Informacja o wyjatku: \n"
                 << "   " << sMessage << "\n";
            XMLString::release(&sMessage);
            return false;
   }
   catch (const SAXParseException& Exception) {
            char* sMessage = XMLString::transcode(Exception.getMessage());
            char* sSystemId = xercesc::XMLString::transcode(Exception.getSystemId());

            cerr << "Blad! " << endl
                 << "    Plik:  " << sSystemId << endl
                 << "   Linia: " << Exception.getLineNumber() << endl
                 << " Kolumna: " << Exception.getColumnNumber() << endl
                 << " Informacja: " << sMessage 
                 << endl;

            XMLString::release(&sMessage);
            XMLString::release(&sSystemId);
            return false;
   }
   catch (...) {
            cout << "Zgloszony zostal nieoczekiwany wyjatek!\n" ;
            return false;
   }

   delete pParser;
   delete pHandler;
   return true;
}


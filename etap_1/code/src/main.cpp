#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <sstream>

using namespace std;

#include "Interp4Command.hh"
#include "MobileObj.hh"
#include "LibInterface.hh"
#include "Set4LibInterfaces.hh"


#define LINE_SIZE 500

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
		cout << stream.str();
		Set4LibInterfaces interfaces;
		interfaces.addInterface("libInterp4Set.so");
		interfaces.addInterface("libInterp4Move.so");
		interfaces.addInterface("libInterp4Rotate.so");
		interfaces.addInterface("libInterp4Pause.so");

		std::string cmd_name, obj;
		while (stream >> cmd_name) {
			stream >> obj;
			auto cmd = interfaces.map[cmd_name]->pCreateCmd();
			if (!cmd->ReadParams(stream)) {
				cerr << "Wczytywanie parametrow nie powiodlo sie" << endl;
			}
			cmd->PrintCmd();
		}
	}


	/* TEST 
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

#ifndef	LIBINTERFACE_HH
#define LIBINTERFACE_HH

#include <iostream>
#include <string>

#include "Interp4Command.hh"

class LibInterface {
private:
	void* _libHandler;
public:
	std::string cmdName;
	Interp4Command *(*pCreateCmd)(void);
public:
	LibInterface(): _libHandler(nullptr), cmdName("unnamed cmd"), pCreateCmd(nullptr)
	{}
	~LibInterface() {
		dlclose(_libHandler);
	}
	bool init(std::string pluginPath) {
		void *pFunCreateCmd = nullptr;
		_libHandler = dlopen(pluginPath.c_str(), RTLD_LAZY);
		if (!_libHandler) {
			cerr << "!!! Brak biblioteki: " << pluginPath << endl;
			return false;
		}
		pFunCreateCmd = dlsym(_libHandler, "CreateCmd");
		if (!pFunCreateCmd) {
			cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
			return false;
		}
		pCreateCmd = *reinterpret_cast<Interp4Command* (**)(void)>(&pFunCreateCmd);
		auto pCmd = pCreateCmd();
		cmdName = pCmd->GetCmdName();
		delete pCmd; // memleak
		return true;
	}
};
#endif

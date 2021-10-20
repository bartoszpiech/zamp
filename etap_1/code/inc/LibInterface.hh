#ifndef	LIBINTERFACE_HH
#define LIBINTERFACE_HH

#include <iostream>
#include <string>

#include "Interp4Command.hh"

class LibInterface {
//private:
public:
	void* _libHandler;
	std::string _cmdName;
	Interp4Command *(*_pCreateCmd)(void);
public:
	LibInterface(): _libHandler(nullptr), _cmdName("unnamed cmd"), _pCreateCmd(nullptr)
	{}
	~LibInterface() {};

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
		_pCreateCmd = *reinterpret_cast<Interp4Command* (**)(void)>(&pFunCreateCmd);
		auto pCmd = _pCreateCmd();
		_cmdName = pCmd->GetCmdName();
		return true;
	}
};
#endif

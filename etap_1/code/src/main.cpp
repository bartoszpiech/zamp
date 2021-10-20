#include <iostream>
#include <dlfcn.h>
#include <cassert>

using namespace std;

#include "Interp4Command.hh"
#include "MobileObj.hh"
#include "LibInterface.hh"

int main() {
	LibInterface setInterface;
	setInterface.init("libInterp4Set.so");
	cout << "SET INTERFACE: " << setInterface._cmdName << endl;

	void *pLibHnd_Move = dlopen("libInterp4Move.so",RTLD_LAZY);
	Interp4Command *(*pCreateCmd_Move)(void);
	void *pFun_Move;
	if (!pLibHnd_Move) {
		cerr << "!!! Brak biblioteki: Interp4Move.so" << endl;
		return 1;
	}
	pFun_Move = dlsym(pLibHnd_Move,"CreateCmd");

	if (!pFun_Move) {
		cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
		return 1;
	}
	pCreateCmd_Move = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun_Move);

	Interp4Command *pCmd_Move = pCreateCmd_Move();
	Interp4Command *pCmd_Set = setInterface._pCreateCmd();

	cout << endl;
	cout << pCmd_Move->GetCmdName() << endl;
	cout << endl;
	cout << pCmd_Set->GetCmdName() << endl;
	cout << endl;
	pCmd_Move->PrintSyntax();
	cout << endl;
	pCmd_Move->PrintCmd();
	cout << endl;
	pCmd_Set->PrintSyntax();
	cout << endl;
	pCmd_Set->PrintCmd();
	cout << endl;
	delete pCmd_Move;
	dlclose(pLibHnd_Move);
}

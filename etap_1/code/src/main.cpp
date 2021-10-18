#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "Interp4Command.hh"
#include "MobileObj.hh"

using namespace std;

int main() {
	void *pLibHnd_Move = dlopen("libInterp4Move.so",RTLD_LAZY);
	void *pLibHnd_Set = dlopen("libInterp4Set.so",RTLD_LAZY);
	Interp4Command *(*pCreateCmd_Move)(void);
	Interp4Command *(*pCreateCmd_Set)(void);
	void *pFun_Move;
	void *pFun_Set;

	if (!pLibHnd_Move) {
		cerr << "!!! Brak biblioteki: Interp4Move.so" << endl;
		return 1;
	}
	if (!pLibHnd_Set) {
		cerr << "!!! Brak biblioteki: Interp4Set.so" << endl;
		return 1;
	}

	pFun_Move = dlsym(pLibHnd_Move,"CreateCmd");
	pFun_Set = dlsym(pLibHnd_Set,"CreateCmd");

	if (!pFun_Move) {
		cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
		return 1;
	}
	if (!pFun_Set) {
		cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
		return 1;
	}

	pCreateCmd_Move = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun_Move);
	pCreateCmd_Set = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun_Set);


	Interp4Command *pCmd_Move = pCreateCmd_Move();
	Interp4Command *pCmd_Set = pCreateCmd_Set();

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
	delete pCmd_Set;

	dlclose(pLibHnd_Move);
	dlclose(pLibHnd_Set);
}

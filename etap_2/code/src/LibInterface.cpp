#include "LibInterface.hh"


bool init(const std::string &pluginPath) {
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
    delete pCmd; // memleak protection
    return true;
}

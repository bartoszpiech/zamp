#include "LibInterface.hh"


bool LibInterface::init(const std::string &pluginPath) {
    void *pFunCreateCmd = nullptr;
    _libHandler = dlopen(pluginPath.c_str(), RTLD_LAZY);
    if (!_libHandler) {
        std::cerr << "!!! Brak biblioteki: " << pluginPath << std::endl;
        return false;
    }
    pFunCreateCmd = dlsym(_libHandler, "CreateCmd");
    if (!pFunCreateCmd) {
        std::cerr << "!!! Nie znaleziono funkcji CreateCmd" << std::endl;
        return false;
    }
    pCreateCmd = *reinterpret_cast<Interp4Command* (**)(void)>(&pFunCreateCmd);
    auto pCmd = pCreateCmd();
    cmdName = pCmd->GetCmdName();
    delete pCmd; // memleak protection
    return true;
}

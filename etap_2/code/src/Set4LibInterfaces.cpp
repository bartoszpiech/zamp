#include "Set4LibInterfaces.hh"


bool Set4LibInterfaces::addInterface(std::string &interfacePath) {
    auto pInterface = std::make_shared<LibInterface>();
    if (!(pInterface->init(interfacePath))) {
        std::cerr << "!!! Dodanie interfejsu ze sciezki " << interfacePath
            << " nie powiodlo sie" << std::endl;
        return false;
    }
    map[pInterface->cmdName] = pInterface;
    return true;
}

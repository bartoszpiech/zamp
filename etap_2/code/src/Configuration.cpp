#include "Configuration.hh"

std::map<std::string, std::shared_ptr<MobileObj>> Configuration::getMobileObjects() {
    return MobileObjects;
}
std::vector<std::string> Configuration::getLibraries() {
    return Libraries;
}
void Configuration::addMobileObject(std::string objName, std::shared_ptr<MobileObj> pMobObj) {
    MobileObjects[objName] = pMobObj;
}
void Configuration::addLibrary(std::string library) {
    Libraries.push_back(library);
}

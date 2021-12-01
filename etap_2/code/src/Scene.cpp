#include "Scene.hh"

std::shared_ptr<MobileObj> Scene::findMobileObj(const char *sObjName) {
    std::string objName(sObjName);
    auto search = MobileObjects.find(objName);
    if (search != MobileObjects.end()) {
        return search->second;
    }
    return nullptr;
}

std::shared_ptr<MobileObj> Scene::findMobileObj(const std::string &rObjName) {
    auto search = MobileObjects.find(rObjName);
    if (search != MobileObjects.end()) {
        return search->second;
    }
    return nullptr;
}

void Scene::AddMobileObj(const std::string &rObjName, std::shared_ptr<MobileObj> pMobObj) {
    MobileObjects[rObjName] = pMobObj;
}

void Scene::AddMobileObj(const char *sObjName, std::shared_ptr<MobileObj> pMobObj) {
    std::string objName(sObjName);
    MobileObjects[objName] = pMobObj;
}

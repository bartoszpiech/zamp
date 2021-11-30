#ifndef SCENE_HH
#define SCENE_hh

#include <map>
#include <memory>

#include "MobileObj.hh"

class Scene {
private:
    std::map<std::string, std::shared_ptr<MobileObj>> MobileObjects;
public:
    Scene() {}
    ~Scene() {}
    std::shared_ptr<MobileObj> findMobileObj(const char *sObjName);
    std::shared_ptr<MobileObj> findMobileObj(const std::string &rObjName);
    void AddMobileObj(const char *sObjName, std::shared_ptr<MobileObj> pMobObj);
    void AddMobileObj(const std::string &rObjName, std::shared_ptr<MobileObj> pMobObj);
};

#endif

#ifndef SCENE_HH
#define SCENE_HH

#include <map>
#include <memory>

#include "MobileObj.hh"
#include "AccessControl.hh"

class Scene : public AccessControl {
private:
    std::map<std::string, std::shared_ptr<MobileObj>> MobileObjects;
public:
    Scene() {}
    ~Scene() {}
    auto GetMobileObjects() { return MobileObjects; };
    std::shared_ptr<MobileObj> findMobileObj(const char *sObjName);
    std::shared_ptr<MobileObj> findMobileObj(const std::string &rObjName);
    void AddMobileObj(const char *sObjName, std::shared_ptr<MobileObj> pMobObj);
    void AddMobileObj(const std::string &rObjName, std::shared_ptr<MobileObj> pMobObj);
};

#endif

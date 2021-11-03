#ifndef SCENE_HH
#define SCENE_hh

#include <map>
#include <memory>

#include "MobileObj.hh"

class Scene {
private:
public:
	std::map<std::string, std::shared_ptr<MobileObj>> setMobileObjs;
public:
	Scene() {}
	~Scene() {}
	std::shared_ptr<MobileObj> findMobileObj(const char *sObjName);
	std::shared_ptr<MobileObj> findMobileObj(const std::string &rObjName);
	void AddMobileObj(std::shared_ptr<MobileObj> pMobObj);
};

#endif

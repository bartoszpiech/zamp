#ifndef CONFIGURATION_HH
#define CONFIGURATION_HH

#include <vector>
#include <map>
#include <memory>
#include <string>


#include "MobileObj.hh"

class Configuration {
private:
	std::map<std::string, std::shared_ptr<MobileObj>> MobileObjects;
	std::vector<std::string> Libraries; 
public:
    std::map<std::string, std::shared_ptr<MobileObj>> getMobileObjects();
	std::vector<std::string> getLibraries();
	void addMobileObject(std::string objName, std::shared_ptr<MobileObj> pMobObj);
	void addLibrary(std::string library);
};

#endif

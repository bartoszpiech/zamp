#ifndef CONFIGURATION_HH
#define CONFIGURATION_HH

#include <vector>
#include <map>
#include <memory>


#include "MobileObj.hh"

class Configuration {
private:
	std::map<std::string, std::shared_ptr<MobileObj>> MobileObjects;
	std::vector<std::string> Libraries; 
public:
	bool addMobileObject(std::string objName, std::shared_ptr<MobileObj> pMobObj);
	bool addLibrary(std::string library);

public:

};


#endif

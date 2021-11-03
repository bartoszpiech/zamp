#ifndef	SET4LIBINTERFACES_HH
#define SET4LIBINTERFACES_HH

#include <map>
#include <memory>

#include "LibInterface.hh"

class Set4LibInterfaces {
//private:
public:
	std::map<string, std::shared_ptr<LibInterface>> map;
public:
	Set4LibInterfaces() {}
	~Set4LibInterfaces() {}
	bool addInterface(std::string interfacePath) {
		auto pInterface = std::make_shared<LibInterface>();
		if (!pInterface->init(interfacePath)) {
			std::cerr << "!!! Dodanie interfejsu ze sciezki " << interfacePath
				<< " nie powiodlo sie" << std::endl;
			return false;
		}
		map[pInterface->cmdName] = pInterface;
		return true;
	}
};
#endif

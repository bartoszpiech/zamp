#ifndef	SET4LIBINTERFACES_HH
#define SET4LIBINTERFACES_HH

#include <map>
#include <memory>

#include "LibInterface.hh"

/*!
 * \file
 * \brief Definicja klasy Set4LibInterfaces
 *
 * Plik zawiera definicję klasy Set4LibInterfaces
 */

/*!
 * \brief Modeluje zbiór bibliotek ładowanych dynamicznie.
 *
 *  Klasa posiada pole map ze Standardowej biblioteki szablonów.
 */
class Set4LibInterfaces {
//private:
public:
   /*!
    * \brief Mapa z STL, łączy nazwę polecenia, np. Set, oraz inteligentny
	* wskaźnik na interfejs biblioteki.
    */
	std::map<string, std::shared_ptr<LibInterface>> map;
public:
   /*!
    * \brief Konstruktor domyślny klasy Set4LibInterfaces
    */
	Set4LibInterfaces() {}
   /*!
    * \brief Destruktor domyślny klasy Set4LibInterfaces
    */
	~Set4LibInterfaces() {}
   /*!
    * \brief Metoda AddInterface, pozwala dodać bibliotekę do mapy
    */
	bool addInterface(const std::string &interfacePath) {
		auto pInterface = std::make_shared<LibInterface>();
		if (!(pInterface->init(interfacePath))) {
			std::cerr << "!!! Dodanie interfejsu ze sciezki " << interfacePath
				<< " nie powiodlo sie" << std::endl;
			return false;
		}
		map[pInterface->cmdName] = pInterface;
		return true;
	}
};
#endif

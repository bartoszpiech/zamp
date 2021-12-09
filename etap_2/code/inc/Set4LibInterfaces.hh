#ifndef	SET4LIBINTERFACES_HH
#define SET4LIBINTERFACES_HH

#include <map>
#include <memory>
#include <string>

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
	std::map<std::string, std::shared_ptr<LibInterface>> map;
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
	bool addInterface(std::string &interfacePath);
};
#endif

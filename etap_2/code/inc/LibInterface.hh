#ifndef	LIBINTERFACE_HH
#define LIBINTERFACE_HH

#include <iostream>
#include <string>
#include <dlfcn.h>

#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy LibInterface
 *
 * Plik zawiera definicję klasy LibInterface.
 */

/*!
 * \brief Modeluje interfejs wtyczkek, które implementują konkretne komendy
 */
class LibInterface {
private:
   /*!
    * \brief Uchwyt na bibliotekę dynamiczną.
    */
	void* _libHandler;
public:
   /*!
    * \brief Nazwa komendy ładowanej przez wtyczkę.
    */
	std::string cmdName;
   /*!
    * \brief Uchwyt na wskaźnik funkcji, która tworzy interfejs polecenia
    */
	Interp4Command *(*pCreateCmd)(void);
public:
   /*!
    * \brief Konstruktor klasy LibInterface tworzący instancję z domyślnymi
	* wartościami.
    */
    //LibInterface();
    /*
	LibInterface(): _libHandler(nullptr), cmdName("unnamed cmd"), pCreateCmd(nullptr)
	{}
    */
   /*!
    * \brief Destruktor klasy, zamyka uchwyt do dynamicznej biblioteki.
    */
	~LibInterface() {
        /*
        if (_libHandler != nullptr) {
            dlclose(_libHandler);
        }
        */
	}
   /*!
    * \brief Metoda ładująca bibliotekę.
    */
	bool init(std::string &pluginPath);
};
#endif

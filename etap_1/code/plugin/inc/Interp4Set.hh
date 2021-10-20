#ifndef  COMMAND4SET_HH
#define  COMMAND4SET_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include <string>

#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Set
 *
 * Plik zawiera definicję klasy Interp4Set ...
 */

/*!
 * \brief Modeluje polecenie dla robota mobilnego, które wymusza jego ruch do przodu
 *
 *  Klasa modeluje ...
 */
class Interp4Set: public Interp4Command {
	std::string _name;
	double _coord_x, _coord_y;
	double _angle_ox, _angle_oy, _angle_oz;

public:
	/*!
	* \brief
	*/
	Interp4Set();
	/*!
	* \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
	*/
	virtual void PrintCmd() const;
	/*!
	* \brief Wyświetla składnię polecenia
	*/
	virtual void PrintSyntax() const;
	/*!
	* \brief Wyświetla nazwę polecenia
	*/
	virtual const char* GetCmdName() const;
	/*!
	* \brief Wykonuje polecenie oraz wizualizuje jego realizację
	*/
	virtual bool ExecCmd( MobileObj  *pMobObj, int Socket) const;
	/*!
	* \brief Czyta wartości parametrów danego polecenia
	*/
	virtual bool ReadParams(std::istream& Strm_CmdsList);
	/*!
	* \brief Wyświetla wartości wczytanych parametrów
	*/
	virtual void PrintParams() {}
	/*!
	* \brief
	*
	*  Ta metoda nie musi być zdefiniowna w klasie bazowej.
	*/
	static Interp4Command* CreateCmd();
};

#endif
#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include <string>

#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Rotate
 *
 * Plik zawiera definicję klasy Interp4Rotate ...
 */

/*!
 * \brief Modeluje polecenie dla robota mobilnego, które wymusza jego rotację
 *
 *  Klasa modeluje ...
 */
class Interp4Rotate: public Interp4Command {
	/*!
	 * \brief Nazwa obiektu.
	 */
	std::string _name;
	/*!
	 * \brief Szybkość kątowa obiektu.
	 */
	double  _ang_speed;
	/*!
	 * \brief Oś obrotu.
	 */
	char _axis;
	/*!
	 * \brief Kąt obrotu.
	 */
	double  _angle;

	public:
	/*!
	* \brief Konstruktor klasy Rotate.
	*/
	Interp4Rotate();  
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
	* Ta metoda nie musi być zdefiniowna w klasie bazowej.
	*/
	static Interp4Command* CreateCmd();
};

#endif

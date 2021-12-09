#ifndef  COMMAND4SET_HH
#define  COMMAND4SET_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "Interp4Command.hh"
#include <string>

/*!
 * \file
 * \brief Definicja klasy Interp4Set
 *
 * Plik zawiera definicję klasy Interp4Set, ktora modeluje ustawianie obiektu
 */

/*!
 * \brief Modeluje polecenie ustawienia robota mobilnego w zadanym miejscu na scenie
 *
 *  Klasa modeluje ustawienie obiektu w zadanym miejscu
 */
class Interp4Set: public Interp4Command {
  std::string ObjectName; // nazwa obiektu
  double  _cordX; // wspolrzedna X
  double  _cordY; // wspolrzedna Y
  double  _angX; // kat X
  double  _angY; // kat Y
  double  _angZ; // kat Z
 public:
  /*!
   * \brief Konstruktor
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
   * \brief Wyświetla nazwę obiektu
   */
  virtual std::string GetObjName() const;
  /*!
   * \brief Wykonuje polecenie oraz wizualizuje jego realizację
   */
  //virtual bool ExecCmd( MobileObj  *pMobObj, int Socket) const;
  virtual bool ExecCmd(MobileObj *pMobObj, AccessControl *pAccCtrl) const;
  /*!
   * \brief Czyta wartości parametrów danego polecenia
   */
  virtual bool ReadParams(std::istream& Strm_CmdsList);
  /*!
   * \brief Wyświetla wartości wczytanych parametrów
   */
  virtual void PrintParams() {}
  /*!
   * \brief Metoda, ktora tworzy interfejs komendy.
   */
  static Interp4Command* CreateCmd();
 };

#endif

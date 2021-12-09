#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Move
 *
 * Plik zawiera definicję klasy Interp4Move, ktora modeluje ruch obiektu w przod.
 */

/*!
 * \brief Modeluje polecenie dla robota mobilnego, które wymusza jego ruch do przodu
 *
 *  Klasa modeluje ruch w przod o zadana wartosc z zadana szybkoscia.
 */
class Interp4Move: public Interp4Command {

  std::string ObjectName; //nazwa obiektu do poruszenia
  double  _Speed_mmS; // predkosc zadana z jaka obiekt ma sie poruszyc [mms]
  double _Path_Length; // odleglosc jaka ma przejechac
 public:
  /*!
   * \brief Konstruktor
   */
  Interp4Move();  
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
   * \brief Metoda, ktora tworzy interfejs komendy
   */
  static Interp4Command* CreateCmd();
 };

#endif

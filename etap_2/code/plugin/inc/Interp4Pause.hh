#ifndef  COMMAND4PAUSE_HH
#define  COMMAND4PAUSE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Pause
 *
 * Plik zawiera definicję klasy Interp4Pause, ktora modeluje zatrzymywanie sie
 * okreslonego obiektu na zadany czas
 */

/*!
 * \brief Modeluje polecenie dla robota mobilnego, które wymusza jego zawieszenie działania
 *
 *  Klasa modeluje polecenie zawieszenia sie obiektu na zadany okres czasu. W tym czasie nie wykonuje innych akcji.
 */
class Interp4Pause: public Interp4Command {

private:
  unsigned int delay; // czas na jaki ma się zatrzymać [ms]


 public:
  /*!
   * \brief Kokstruktor
   */
  Interp4Pause();  
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
   * \brief Metoda ta tworzy interfejs komendy.
   */
  static Interp4Command* CreateCmd();
 };

#endif

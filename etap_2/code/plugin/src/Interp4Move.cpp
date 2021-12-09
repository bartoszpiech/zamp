#include <iostream>
#include "Interp4Move.hh"
#include "MobileObj.hh"
#include <cmath>

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Move"; }
}


Interp4Command* CreateCmd(void)
{
  return Interp4Move::CreateCmd();
}


Interp4Move::Interp4Move(): ObjectName("NoName"), _Speed_mmS(0)
{}


void Interp4Move::PrintCmd() const
{
  cout << GetCmdName() << " "<< ObjectName << " " << _Speed_mmS  << " " << _Path_Length << endl;
}


const char* Interp4Move::GetCmdName() const
{
  return ::GetCmdName();
}

std::string Interp4Move::GetObjName() const
{
  return ObjectName;
}

bool Interp4Move::ExecCmd(MobileObj *pMobObj, AccessControl *pAccCtrl) const
{
  double Speed_mS = _Speed_mmS / 1000;
  Vector3D position; // Pozycja obiektu
  double angle = pMobObj->GetAng_Yaw_deg();

  int direction = 1;
  if (_Path_Length < 0)
  {
    direction = -1;
  }

  // Animacja i wykonywanie ruchu
  for (int step = 0; step < 10 * abs(_Path_Length); step++) //steps; step++)
  {
  // Zablokowanie dostępu
    pAccCtrl->LockAccess();

   // Pobranie aktualnej pozycji obiektu
    Vector3D position = pMobObj->GetPosition_m();

    // Pozycja na osiach X i Y
    // Każdy "step" to jedna sekunda drogi,
    // a Speed_mS to prędkość w metrach na sekundę,
    // więc Speed_mS wyznacza odcinek drogi do przebycia.
    position[0] += direction * 0.1 * cos(M_PI * angle / 180);
    position[1] += direction * 0.1 * sin(M_PI * angle / 180);

    // Zapisanie nowej pozycji obiektu
    pMobObj->SetPosition_m(position);

    // Zapisanie zmian
    pAccCtrl->MarkChange();

    // Odblokowanie dostępu
    pAccCtrl->UnlockAccess();
    usleep(50000 * 1 / Speed_mS);
  }


  return true;
}

bool Interp4Move::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >> ObjectName >> _Speed_mmS >> _Path_Length;
  return true;
}

Interp4Command* Interp4Move::CreateCmd()
{
  return new Interp4Move();
}

void Interp4Move::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}

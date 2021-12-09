#include <iostream>
#include "Interp4Rotate.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Rotate"; }
}


Interp4Command* CreateCmd(void)
{
  return Interp4Rotate::CreateCmd();
}


Interp4Rotate::Interp4Rotate(): ObjectName("NoName"), angular_speed(0), axis_name('X'), rotation_angle(0)
{}


void Interp4Rotate::PrintCmd() const
{
  cout << GetCmdName() << " " << ObjectName << " " << angular_speed << " " << axis_name << " " << rotation_angle << " " << endl;
}


const char* Interp4Rotate::GetCmdName() const
{
  return ::GetCmdName();
}


std::string Interp4Rotate::GetObjName() const
{
  return ObjectName;
}


bool Interp4Rotate::ExecCmd(MobileObj *pMobObj, AccessControl *pAccCtrl) const
{
  double angle;
  Vector3D tmp_pos, zeros;

  zeros[0] = 0;
  zeros[1] = 0;
  zeros[2] = 0;

  switch (axis_name)
  {
  case 'X':
    angle = pMobObj->GetAng_Roll_deg();
    break;
  case 'Y':
    angle = pMobObj->GetAng_Pitch_deg();
    break;
  case 'Z':
    angle = pMobObj->GetAng_Yaw_deg();
    break;
  }

  // Animacja i wykonywanie ruchu
  for (int step = 0; step < rotation_angle; step += 5) //steps; step++)
  {
    // Zablokowanie dostępu
    pAccCtrl->LockAccess();

    // Wykonanie obrotu
    // Każdy "step" to jedna sekunda obrotu,
    // a _Angular_speed_degS to prędkość obrotu w stopniach na sekundę,
    // więc _Angular_speed_degS wyznacza kąt obrotu.
    angle += 5; //_Angular_speed_degS / 10;

    // Zapisanie nowych kątów
    switch (axis_name)
    {
    case 'X':
      pMobObj->SetAng_Roll_deg(angle);
      break;
    case 'Y':
      pMobObj->SetAng_Pitch_deg(angle);
      break;
    case 'Z':
      pMobObj->SetAng_Yaw_deg(angle);
      break;
    }

    // Zapisanie zmian
    pAccCtrl->MarkChange();

    // Odblokowanie dostępu
    pAccCtrl->UnlockAccess();
    usleep(100000); // / _Angular_speed_degS);

  }
  return true;
}


bool Interp4Rotate::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >> ObjectName >> angular_speed >> axis_name >> rotation_angle;
  return true;
}

Interp4Command* Interp4Rotate::CreateCmd()
{
  return new Interp4Rotate();
}

void Interp4Rotate::PrintSyntax() const
{
  cout << "   Rotate  NazwaObiektu  SzybkoscKatowa[deg/s]  NazwaOsi  KatObrotu[deg]" << endl;
}

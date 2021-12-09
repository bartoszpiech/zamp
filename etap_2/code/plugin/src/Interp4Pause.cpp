#include <iostream>
#include "Interp4Pause.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Pause"; }
}

Interp4Command* CreateCmd(void)
{
  return Interp4Pause::CreateCmd();
}

Interp4Pause::Interp4Pause(): delay(0)
{}

void Interp4Pause::PrintCmd() const
{
  cout << GetCmdName() << " " << delay << endl;
}

const char* Interp4Pause::GetCmdName() const
{
  return ::GetCmdName();
}

std::string Interp4Pause::GetObjName() const
{
  return "cos";
}

bool Interp4Pause::ExecCmd(MobileObj *pMobObj, AccessControl *pAccCtrl) const
{
  // Zablokowanie dostępu
  pAccCtrl->LockAccess();

  // Odczekania
  usleep(delay* 1000);

  // Odblokowanie dostępu
  pAccCtrl->UnlockAccess();
  return true;
}

bool Interp4Pause::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >> delay;
  return true;
}


Interp4Command* Interp4Pause::CreateCmd()
{
  return new Interp4Pause();
}


void Interp4Pause::PrintSyntax() const
{
  cout << "   Pause  CzasPauzy[ms]" << endl;
}

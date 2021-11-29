#include <iostream>
#include "Interp4Pause.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;

extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Pause"; }
}

/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void) {
	return Interp4Pause::CreateCmd();
}

/*!
 *
 */
Interp4Pause::Interp4Pause(): _time(0)
{}

/*!
 *
 */
void Interp4Pause::PrintCmd() const {
	cout << GetCmdName() << ' ' << _time << endl;
}

/*!
 *
 */
const char* Interp4Pause::GetCmdName() const {
	return ::GetCmdName();
}

/*!
 *
 */
bool Interp4Pause::ExecCmd( MobileObj  *pMobObj,  int  Socket) const {
	/*
	*  Tu trzeba napisać odpowiedni kod.
	*/
	return true;
}

/*!
 *
 */
bool Interp4Pause::ReadParams(std::istream& Strm_CmdsList) {
	Strm_CmdsList >> _time;
	return !Strm_CmdsList.fail();
}

/*!
 *
 */
Interp4Command* Interp4Pause::CreateCmd() {
	return new Interp4Pause();
}

/*!
 *
 */
void Interp4Pause::PrintSyntax() const {
	cout << "   Pause NazwaObiektu CzasPauzy[ms]" << endl;
}

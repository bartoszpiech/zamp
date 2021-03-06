#include <iostream>
#include "Interp4Move.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;

extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Move"; }
}

/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void) {
	return Interp4Move::CreateCmd();
}

/*!
 *
 */
Interp4Move::Interp4Move(): _name("unnamed"), _speed(0), _distance(0)
{}

/*!
 *
 */
void Interp4Move::PrintCmd() const {
	cout << GetCmdName() << ' ' << _name << ' ' << _speed << ' ' << _distance << endl;
}

/*!
 *
 */
const char* Interp4Move::GetCmdName() const {
	return ::GetCmdName();
}

/*!
 *
 */
bool Interp4Move::ExecCmd( MobileObj  *pMobObj,  int  Socket) const {
	/*
	*  Tu trzeba napisać odpowiedni kod.
	*/
	return true;
}

/*!
 *
 */
bool Interp4Move::ReadParams(std::istream& Strm_CmdsList) {
	Strm_CmdsList >> _name >> _speed >> _distance;
	return !Strm_CmdsList.fail();
}

/*!
 *
 */
Interp4Command* Interp4Move::CreateCmd() {
	return new Interp4Move();
}

/*!
 *
 */
void Interp4Move::PrintSyntax() const {
	cout << "   Move NazwaObiektu Szybkosc[m/s] DlugoscDrogi[m]" << endl;
}

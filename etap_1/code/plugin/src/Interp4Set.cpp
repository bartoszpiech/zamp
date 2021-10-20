#include <iostream>
#include "Interp4Set.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;

extern "C" {
	Interp4Command* CreateCmd(void);
	const char* GetCmdName() { return "Set"; }
}

/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void) {
	return Interp4Set::CreateCmd();
}

/*!
 *
 */
Interp4Set::Interp4Set():	_name("unnamed"), _coord_x(0), _coord_y(0),
							_angle_ox(0), _angle_oy(0), _angle_oz(0)
{}

/*!
 *
 */
void Interp4Set::PrintCmd() const {
	cout << GetCmdName() << ' ' << _name << ' '
		<< _coord_x << ' ' << _coord_y << ' '
		<< _angle_ox << ' ' << _angle_oy << ' ' << _angle_oz << endl;
}

/*!
 *
 */
const char* Interp4Set::GetCmdName() const {
  return ::GetCmdName();
}

/*!
 *
 */
bool Interp4Set::ExecCmd( MobileObj  *pMobObj,  int  Socket) const {
	/*
	*  Tu trzeba napisać odpowiedni kod.
	*/
	return true;
}

/*!
 *
 */
bool Interp4Set::ReadParams(std::istream& Strm_CmdsList) {
	/*
	*  Tu trzeba napisać odpowiedni kod.
	*/
	return true;
}

/*!
 *
 */
Interp4Command* Interp4Set::CreateCmd() {
	return new Interp4Set();
}

/*!
 *
 */
void Interp4Set::PrintSyntax() const {
	cout << "   Set NazwaObiektu WspolrzednaX WspolrzednaY kat_OX[st] kat_OY[st] kat_OZ[st]" << endl;
}

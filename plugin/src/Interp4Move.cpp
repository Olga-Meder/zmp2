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
Interp4Command* CreateCmd(void)
{
  return Interp4Move::CreateCmd();
}


/*!
 *
 */
Interp4Move::Interp4Move(): _Name(""), _Speed_mmS(0), _length_m(0)
{}


/*!
 *
 */
void Interp4Move::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout <<"   "<< GetCmdName() << " " <<_Name << " "<<  _Speed_mmS  << " "<<_length_m  << endl;
}


/*!
 *
 */
const char* Interp4Move::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Move::ExecCmd( MobileObj  *pMobObj,  int  Socket) const
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
bool Interp4Move::ReadParams(std::istream& Strm_CmdsList)
{
    if (!(Strm_CmdsList >> _Name))
    {
        std::cout << "Blad wczytywania nazwy" << std::endl;
        return 1;
    }

    if (!(Strm_CmdsList >> _Speed_mmS))
    {
        std::cout << "Blad wczytywania pozycji x" << std::endl;
        return 1;
    }

    if (!(Strm_CmdsList >> _length_m))
    {
        std::cout << "Blad wczytywania pozycji y" << std::endl;
        return 1;
    }

    return 0;

}


/*!
 *
 */
Interp4Command* Interp4Move::CreateCmd()
{
  return new Interp4Move();
}


/*!
 *
 */
void Interp4Move::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}

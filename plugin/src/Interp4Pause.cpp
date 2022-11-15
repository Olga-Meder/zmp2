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
Interp4Command* CreateCmd(void)
{
    return Interp4Pause::CreateCmd();
}


/*!
 *
 */
Interp4Pause::Interp4Pause(): time_ms(0) //time_ms
{}


/*!
 *
 */
void Interp4Pause::PrintCmd() const
{
    /*
     *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
     */
    cout <<"   "<< GetCmdName() << " " << time_ms  << endl;
}


/*!
 *
 */
const char* Interp4Pause::GetCmdName() const
{
    return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Pause::ExecCmd( MobileObj  *pMobObj,  int  Socket) const
{
    /*
     *  Tu trzeba napisać odpowiedni kod.
     */
    return true;
}


/*!
 *
 */
bool Interp4Pause::ReadParams(std::istream& Strm_CmdsList)
{
    if (!(Strm_CmdsList >> time_ms))
    {
        std::cout << "Blad wczytywania czasu" << std::endl;
        return 1;
    }
    return 0;
}


/*!
 *
 */
Interp4Command* Interp4Pause::CreateCmd()
{
    return new Interp4Pause();
}


/*!
 *
 */
void Interp4Pause::PrintSyntax() const
{
    cout << "   Pause  czas[s]" << endl;
}
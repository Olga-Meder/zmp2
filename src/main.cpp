#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <cstdio>
#include <sstream>
#include <string>
#include "LibInterface.hh"
#include "Interp4Command.hh"
#include "MobileObj.hh"
#include "Set4LibInterfaces.hh"

using namespace std;


#define LINE_SIZE 500



//preprocesor czytanie makr
bool ExscPreprocesor(const char *NazwaPliku, istringstream &IStrm4Cmds)
{
    string Cmd4Preproc = "cpp -P ";
    char Line[LINE_SIZE];
    ostringstream OTmpStrm;

    Cmd4Preproc += NazwaPliku;
    FILE* pProc = popen(Cmd4Preproc.c_str(), "r");

    if(!pProc) return false;

    while(fgets(Line,LINE_SIZE,pProc))
    {
        OTmpStrm << Line;
    }
    IStrm4Cmds.str(OTmpStrm.str());
    return pclose(pProc) == 0;
}


int main()
{
    cout << "test" <<endl;
    Set4LibInterfaces Set;
    cout <<"test2" <<endl;
    istringstream stream;
    cout <<"test3" <<endl;

    ExscPreprocesor("dzialanie.cmd",stream);
    cout <<"test4" <<endl;
    Set.init();
    cout <<"test5" <<endl;
    Set.execute(stream);
    cout <<"test6" <<endl;

}

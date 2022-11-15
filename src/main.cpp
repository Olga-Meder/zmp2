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

/*
#define LINE_SIZE 500



//preprocesor czytanie makr
bool ExscPreprocesor(const char *NazwaPliku, istringstream &IStrm4Cmds)
{
    string Cmd4Preproc = "ccp -P";
    char Line[LINE_SIZE];
    ostringstream OTmpStrm;

    Cmd4Preproc += NazwaPliku;
    FILE* pProc = popen(CMd4Preproc.c_str(), "r");

    if(!pProc) return false;

    while(fgets(Line.LINE_SIZE,pProc))
    {
        OTmpStrm << Line;
    }
    IStrm4Cmds.str(OTmpStrm.str());
    return pclose(pProc) == 0;
}
*/

int main()
{

    //konkretny przykład dla wtyczki move, my musimy zrobić w wLibInterface ogolne
  void *pLibHnd_Move = dlopen("libInterp4Move.so",RTLD_LAZY);
  Interp4Command *(*pCreateCmd_Move)(void);
  void *pFun;

  if (!pLibHnd_Move) {
    cerr << "!!! Brak biblioteki: Interp4Move.so" << endl;
    return 1;
  }


  pFun = dlsym(pLibHnd_Move,"CreateCmd");
  if (!pFun) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }
  pCreateCmd_Move = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);


  Interp4Command *pCmd = pCreateCmd_Move();

  cout << endl;
  cout << pCmd->GetCmdName() << endl;
  cout << endl;
  pCmd->PrintSyntax();
  cout << endl;
  pCmd->PrintCmd();
  cout << endl;
  
  delete pCmd;

  dlclose(pLibHnd_Move);
}

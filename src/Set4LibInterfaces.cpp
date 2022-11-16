#include "Set4LibInterfaces.hh"

using namespace std;

bool Set4LibInterfaces::init()
{
    rt->init("libs/libInterp4Rotate.so");
    ps->init("libs/libInterp4Pause.so");
    st->init("libs/libInterp4Set.so");
    mv->init("libs/libInterp4Move.so");

    Lib.insert(make_pair("Rotate", rt));
    Lib.insert(make_pair("Pause", ps));
    Lib.insert(make_pair("Set", st));
    Lib.insert(make_pair("Move", mv));

    return 0;
}



bool Set4LibInterfaces::execute(istringstream &stream)
{
    string str;
    LibInterface *Lib_;
    Interp4Command *cmd;

    while (stream >> str)
    {
        map<string, LibInterface *>::iterator it = Lib.find(str); //znajduje stringa

        Lib_= it -> second; //wskaznik na biblioteke
        cmd = Lib_->CreateCmd();
        cmd->ReadParams(stream);
        cmd->PrintCmd();
        delete cmd;
    }

    return 0;
}

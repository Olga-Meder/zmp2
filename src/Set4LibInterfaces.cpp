#include "Set4LibInterfaces.hh"

using namespace std;

bool Set4LibInterfaces::init()
{

    std::string tekst = "libs/libInterp4Rotate.so";
    rt->init(tekst);
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
        map<string, LibInterface *>::iterator it = Lib.find(str);


        cmd = Lib_->CreateCmd();
        cmd->ReadParams(stream);
        cmd->PrintCmd();
        delete cmd;
    }

    return 0;
}

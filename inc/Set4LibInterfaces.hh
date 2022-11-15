#pragma once

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include "LibInterface.hh"
#include "Interp4Command.hh"
#include <vector>
#include <memory>


class Set4LibInterfaces
{
private:
    std::map<std::string, LibInterface *> Lib;

public:
    bool init();

    LibInterface *rt = new LibInterface();
    LibInterface *ps = new LibInterface();
    LibInterface *st = new LibInterface();
    LibInterface *mv = new LibInterface();

//    bool execute(std::istringstream &stream);
};
#include "Name.h"

Name::Name(std::vector<std::string> ns)
    : names(ns)
{

}

std::string Name::get()
{
    Random r(0, 3);

    std::string chosenName = names[r.get()];
    names.erase(std::remove(names.begin(), names.end(), chosenName), names.end());
    
    return chosenName;
}
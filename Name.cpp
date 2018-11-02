#include "Name.h"
#include "Random.h"

Name::Name(std::vector<std::string> ns)
    : names(ns)
{

}

std::string Name::get()
{
    Random r(0, 3);
    int ran = r.get();

    std::string chosenName = names[ran];
    return chosenName;
}
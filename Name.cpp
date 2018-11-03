#include "Name.h"

Name::Name(std::vector<std::string> ns)
    : names(ns)
{

}

std::string Name::get()
{
    Random r(0, 3);
    int ran = r.get();

    std::cout << "Got #" << ran << std::endl;

    std::string chosenName = names[ran];
    return chosenName;
}
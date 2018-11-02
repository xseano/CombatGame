#include "Project.h"
#include "Name.h"

int main()
{
    std::vector<std::string> names;
    registerNames(&names);

    Name nameGen(names);
    std::string name = nameGen.get();

    std::cout << "Welcome, " << name << "." << std::endl;
}

void registerNames(std::vector<std::string>* names)
{
    names->push_back("Sir Lancelot");
    names->push_back("Sir Kaladin");
    names->push_back("Sir Geralt");
    names->push_back("Sir Jamie");
}
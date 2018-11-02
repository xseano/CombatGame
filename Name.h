#ifndef NAME_H
#define NAME_H

#include <iostream>
#include <vector>

class Name
{
    public:
        Name(std::vector<std::string> ns);
        std::string get();
    private:
        std::vector<std::string> names;
};

#endif
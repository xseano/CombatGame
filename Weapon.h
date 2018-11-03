#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
    public:
        Weapon(std::string t, int p, int s);
        void display();
        int getStamina();
        bool did_I_hit();
    private:
        std::string type;
        int probability;
        int stamina;
};

#endif

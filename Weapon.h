#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
    public:
        Weapon(std::string t, int p, int s, int dmg);
        std::string getType();
        void display();
        int getStamina();
        int getDamage();
        bool didHit();
    private:
        std::string type;
        int probability;
        int stamina;
        int damage;
};

#endif

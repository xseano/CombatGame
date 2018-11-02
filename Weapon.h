#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
using namespace std;

class Weapon
{
    public:
        Weapon(string t, int p, int s);
        void display();
        int what_is_stamina_cost();
        bool did_I_hit();
    private:
        string type;
        int probability;
        int stamina;
};

#endif

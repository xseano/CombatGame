#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>

#include "Player.h"
#include "Weapon.h"

class Knight
{
    public:
        Knight(Player player, Weapon weapon);
        Player getPlayer();
        Weapon getWeapon();
        void display();
    private:
        Player player;
        Weapon weapon;
};

#endif
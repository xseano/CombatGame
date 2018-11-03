#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{
    public:
        Player(std::string name, int health, int stamina);
        
        std::string name;
        int health;
        int stamina;

        std::string getName();
        int getHealth();
        int getStamina();
        void addHealth(int amount);
        void addStamina(int amount);
        void deductHealth(int amount);
        void deductStamina(int amount);
};

#endif
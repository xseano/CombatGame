#ifndef PROJECT_H
#define PROJECT_H
#define WEAPON_LIST 4

#include <iostream>
#include <vector>

#include "Name.h"
#include "Player.h"
#include "Weapon.h"

void registerNames(std::vector<std::string>* names);
void registerWeapon(std::vector<Weapon>* weapons, std::string type, int probability, int stamina);

#endif
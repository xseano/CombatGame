#ifndef PROJECT_H
#define PROJECT_H
#define NAME_LEN 4
#define WEAPON_LEN 4

#include <iostream>
#include <vector>

#include "Name.h"
#include "Player.h"
#include "Weapon.h"

void registerName(std::vector<std::string>* names, std::string name);
void registerWeapon(std::vector<Weapon>* weapons, std::string type, int probability, int stamina);

#endif
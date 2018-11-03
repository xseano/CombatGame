#include "Project.h"

int main()
{
    int weaponChoice;

    std::vector<std::string> names;
    registerNames(&names);

    std::vector<Weapon> weapons;
    std::string weaponList[WEAPON_LIST] = {"greatsword", "lance", "rapier", "spear"};

    for (int i = 0; i < (WEAPON_LIST); i++)
    {
        registerWeapon(&weapons, weaponList[i], 100, 50);
    }

    Name nameGen(names);
    std::string name = nameGen.get();

    Player player(name);

    std::cout << "Welcome, " << player.name << "." << std::endl;
    std::cout << "Please choose one of the weapons below: " << std::endl;

    for (int i = 0; i < (WEAPON_LIST); i++)
    {
        std::cout << i << ". " << weaponList[i] << std::endl;
    }

    std::cin >> weaponChoice;

    std::cout << "You chose the weapon: " << weaponList[weaponChoice] << std::endl;
}

void registerWeapon(std::vector<Weapon>* weapons, std::string type, int probability, int stamina)
{
    Weapon wpn(type, probability, stamina);
    weapons->push_back(wpn);
}

void registerNames(std::vector<std::string>* names)
{
    names->push_back("Sir Lancelot");
    names->push_back("Sir Kaladin");
    names->push_back("Sir Geralt");
    names->push_back("Sir Jamie");
}
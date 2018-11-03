#include "Project.h"

int main()
{
    int weaponChoice;

    std::vector<std::string> names;
    std::string nameList[NAME_LEN] = {"Lancelot", "Kaladin", "Geralt", "Jamie"};

    for (int i = 0; i < NAME_LEN; i++)
    {
        registerName(&names, nameList[i]);
    }

    std::vector<Weapon> weapons;
    std::string weaponList[WEAPON_LEN] = {"greatsword", "lance", "rapier", "spear"};

    for (int i = 0; i < WEAPON_LEN; i++)
    {
        registerWeapon(&weapons, weaponList[i], 100, 50);
    }

    Name nameGen(names);
    std::string name = nameGen.get();

    Player player(name);

    std::cout << "Welcome, " << player.name << "." << std::endl;
    std::cout << "Please choose one of the weapons below: " << std::endl;

    for (int i = 0; i < WEAPON_LEN; i++)
    {
        std::cout << i << ". " << weaponList[i] << std::endl;
    }

    std::cin >> weaponChoice;
    Weapon chosenWeapon = weapons[weaponChoice];

    Knight knight(player, chosenWeapon);
    knight.display();
}

void registerWeapon(std::vector<Weapon>* weapons, std::string type, int probability, int stamina)
{
    Weapon wpn(type, probability, stamina);
    weapons->push_back(wpn);
}

void registerName(std::vector<std::string>* names, std::string name)
{
    std::string fullName = "Sir " + name;
    names->push_back(fullName);
}
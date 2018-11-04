#include "Project.h"

int main()
{
    int weaponChoice;

    // Register available names
    std::vector<std::string> names;
    std::string nameList[NAME_LEN] = {"Lancelot", "Kaladin", "Geralt", "Jamie"};

    for (int i = 0; i < NAME_LEN; i++)
    {
        registerName(&names, nameList[i]);
    }

    // Register available weapons
    std::vector<Weapon> weapons;
    std::string weaponList[WEAPON_LEN] = {"greatsword", "lance", "rapier", "spear"};

    for (int i = 0; i < WEAPON_LEN; i++)
    {
        // get random values for both weapon hit-probability and stamina
        int probability = getRandomAmount(100);
        int stamina = getRandomAmount(150);

        registerWeapon(&weapons, weaponList[i], probability, stamina);
    }

    // Initialize Name Generator
    Name nameGen(names);

    // Initialize player/computer with respective health and stamina and a randomized name
    Player player(nameGen.get(), 200, 100);
    Player computer(nameGen.get(), 200, 100);

    std::cout << "Welcome, " << player.name << "." << std::endl;
    std::cout << "Please choose one of the weapons below: " << std::endl;

    for (int i = 0; i < WEAPON_LEN; i++)
    {
        std::cout << i << ". " << weaponList[i] << std::endl;
    }

    // ask user for which weapon they prefer
    std::cin >> weaponChoice;

    Weapon chosenWeapon = weapons[weaponChoice];
    
    // remove weapon from vector so computer/player cannot have the same weapons
    weapons.erase(std::remove(weapons.begin(), weapons.end(), chosenWeapon), weapons.end());

    Weapon randomWeapon = weapons[getRandomAmount(WEAPON_LEN)];

    // Initialize player/computer knight
    Knight knight(player, chosenWeapon);
    Knight cknight(computer, randomWeapon);

    // Get weapon stamina value and add it to existenital player/computer base stamina
    player.addStamina(chosenWeapon.getStamina());
    computer.addStamina(randomWeapon.getStamina());

    while(true)
    {
        if ((player.getHealth() <= 0) || (player.getStamina() <= 0))
        {
            // player died
            break;
            return 0;
        }
        else if ((computer.getHealth() <= 0) || (computer.getStamina() <= 0))
        {
            // computer died
            break;
            return 0;
        }
        else
        {
            playGame(&knight, &cknight);
        }
    }
}

void playGame(Knight* knight, Knight* cknight)
{
    Player player = knight->getPlayer();
    Weapon weapon = knight->getWeapon();

    Player cplayer = cknight->getPlayer();
    Weapon cweapon = cknight->getWeapon();

    std::cout << "player: " << player.getName() << std::endl;
    std::cout << "weapon: " << weapon.getType() << std::endl;

    std::cout << "computer: " << cplayer.getName() << std::endl;
    std::cout << "comp weapon: " << cweapon.getType() << std::endl;
}

void registerWeapon(std::vector<Weapon>* weapons, std::string type, int probability, int stamina)
{
    // Add weapon to weapons vector
    Weapon wpn(type, probability, stamina);
    weapons->push_back(wpn);
}

void registerName(std::vector<std::string>* names, std::string name)
{
    // Add full name to names vector
    std::string fullName = "Sir " + name;
    names->push_back(fullName);
}

int getRandomAmount(int max)
{
    return (rand() % max + 1);
}
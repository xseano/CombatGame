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
        int damage = getRandomAmount(50);

        registerWeapon(&weapons, weaponList[i], probability, stamina, damage);
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

    /*   // GOAL: remove weapon from vector so computer/player cannot have the same weapons
        // this method doesn't work atm
        // destruction of any instance of Weapon in the vector is prohibited, not sure why
        // weapons.erase(std::remove(weapons.begin(), weapons.end(), chosenWeapon), weapons.end());
    */

    Weapon randomWeapon = weapons[getRandomAmount(WEAPON_LEN)];

    // Initialize player/computer knight
    Knight knight(player, chosenWeapon);
    Knight cknight(computer, randomWeapon);

    // Get weapon stamina value and add it to existenital player/computer base stamina
    player.addStamina(chosenWeapon.getStamina());
    computer.addStamina(randomWeapon.getStamina());

    playGame(&knight, &cknight);

    return 0;
}

void playGame(Knight* knight, Knight* cknight)
{

    Player player = knight->getPlayer();
    Weapon weapon = knight->getWeapon();

    Player cplayer = cknight->getPlayer();
    Weapon cweapon = cknight->getWeapon();

    weapon.display();
    cweapon.display();

    while(true)
    {
        if ((player.getHealth() <= 0) || (player.getStamina() <= 0))
        {
            if (player.getHealth() <= 0)
            {
                std::cout << "You have died, therefore losing the match!" << std::endl;
            }
            else if (player.getStamina() <= 0)
            {
                std::cout << "You have become exhausted, therefore losing the match!" << std::endl;
            }

            break;
        }
        else if ((cplayer.getHealth() <= 0) || (cplayer.getStamina() <= 0))
        {
            if (cplayer.getHealth() <= 0)
            {
                std::cout << "The computer has died, therefore losing the match!" << std::endl;
            }
            else if (cplayer.getStamina() <= 0)
            {
                std::cout << "The computer has become exhausted, therefore losing the match!" << std::endl;
            }

            break;
        }
        else
        {
            /*
            std::cout << "player: " << player.getName() << std::endl;
            std::cout << "weapon: " << weapon.getType() << std::endl;

            std::cout << "computer: " << cplayer.getName() << std::endl;
            std::cout << "comp weapon: " << cweapon.getType() << std::endl;
            */

            if (weapon.didHit() == true)
            {
                int dmg = weapon.getDamage();
                int stam = (weapon.getStamina() / 4);

                cplayer.deductHealth(dmg);
                player.deductStamina(stam);

                std::cout << "You successfully hit the computer with " << dmg << " damage, leaving it with " << cplayer.getHealth() << " health points." << std::endl;
            }
            else
            {
                std::cout << "You failed to land a hit on the computer!" << std::endl;
            }

            if (cweapon.didHit() == true)
            {
                int dmg = cweapon.getDamage();
                int stam = (cweapon.getStamina() / 4);

                player.deductHealth(dmg);
                cplayer.deductStamina(stam);

                std::cout << "The computer successfully hit you with " << dmg << " damage, leaving you with " << player.getHealth() << " health points." << std::endl;
            }
            else
            {
                std::cout << "The computer failed to land a hit on you!" << std::endl;
            }
        }
    }
    
    std::cout << "========== RESULTS ============" << std::endl;

    std::cout << "Player: " << player.getName() << std::endl;
    std::cout << player.getName() << "'s Health: " << player.getHealth() << std::endl;
    std::cout << player.getName() << "'s Stamina: " << player.getStamina() << std::endl;
    std::cout << player.getName() << "'s Weapon: " << weapon.getType() << std::endl;
    
    std::cout << std::endl;

    std::cout << "Computer: " << cplayer.getName() << std::endl;
    std::cout << cplayer.getName() << "'s Health: " << cplayer.getHealth() << std::endl;
    std::cout << cplayer.getName() << "'s Stamina: " << cplayer.getStamina() << std::endl;
    std::cout << cplayer.getName() << "'s Weapon: " << cweapon.getType() << std::endl;

    std::cout << "=============================" << std::endl;
}

void registerWeapon(std::vector<Weapon>* weapons, std::string type, int probability, int stamina, int damage)
{
    // Add weapon to weapons vector
    Weapon wpn(type, probability, stamina, damage);
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
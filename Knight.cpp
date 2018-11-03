#include "Knight.h"

Knight::Knight(Player player, Weapon weapon)
    : player(player), weapon(weapon)
{

}

void Knight::display()
{
    // tbw
    std::cout << weapon.getStamina() << std::endl;
}

Player Knight::getPlayer()
{
    return player;
}

Weapon Knight::getWeapon()
{
    return weapon;
}
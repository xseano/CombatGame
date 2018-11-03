#include "Knight.h"

Knight::Knight(Player plyr, Weapon wpn)
    : player(plyr), weapon(wpn)
{

}

void Knight::display()
{
    std::cout << weapon.getStamina() << std::endl;
}
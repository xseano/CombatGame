#include "Weapon.h"
#include "Random.h"

Weapon::Weapon(std::string t, int p, int s, int dmg)
    : type(t), probability(p), stamina(s), damage(dmg)
{

}

std::string Weapon::getType()
{
    return type;
}

int Weapon::getDamage()
{
    return damage;
}

int Weapon::getStamina()
{
    return stamina;
}

bool Weapon::didHit()
{
    Random r(1, 100);
    int ran = r.get();

    if (ran > probability)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Weapon::display()
{
    std::cout << type << " that costs " << stamina << " stamina and has a " << probability << "% chance to hit." << std::endl;
}
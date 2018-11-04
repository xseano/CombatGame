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

    if (r.get() > probability)
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
    std::cout << "The weapon: " << type << " costs " << stamina << " stamina and has a " << probability << "% chance to hit." << std::endl;
}
#include "Weapon.h"
#include "Random.h"

Weapon::Weapon(std::string t, int p, int s)
    : type(t), probability(p), stamina(s)
{

}

int Weapon::what_is_stamina_cost()
{
    return stamina;
}

bool Weapon::did_I_hit()
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
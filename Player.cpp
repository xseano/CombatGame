#include "Player.h"

Player::Player(std::string name, int health, int stamina)
    : name(name), health(health), stamina(stamina)
{

}

std::string Player::getName()
{
    return name;
}

void Player::addHealth(int amount)
{
    health += amount;
}

void Player::addStamina(int amount)
{
    stamina += amount;
}

void Player::deductHealth(int amount)
{
    health -= amount;
}

void Player::deductStamina(int amount)
{
    stamina -= amount;
}

int Player::getHealth()
{
    return health;
}

int Player::getStamina()
{
    return stamina;
}
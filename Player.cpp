#include "Player.h"

Player::Player(std::string name)
    : name(name)
{
    int health = 100;
    int stamina = 200;
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
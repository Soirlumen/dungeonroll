#include "entity.h"

entity::entity(int _h, unsigned int _p, int _is, std::vector<item> _i) : health(_h), power(_p), inventory(_i), inventorysize(_is) {
    //TODO: kontrolovat ze vlozene inventory ma min itemu nez kolik je misto v inventari
}

entity::entity(int _h, unsigned int _p, int _is): health(_h), power(_p), inventorysize(_is)
{
    inventory={};
}

int entity::getHealth()
{
    return health;
}

unsigned int entity::getPower()
{
    return power;
}

void entity::setHealth(int _h)
{
    health = _h;
}

void entity::setPower(unsigned int _p)
{
    power = _p;
}

bool entity::isAlive()
{
    if (getHealth() > 0)
    {
        return true;
    }
    return false;
}

std::vector<item> &entity::getInventory()
{
    return inventory;
}

void entity::addInInventory(item what)
{
    if (inventory.size() <= inventorysize)
    {
        inventory.push_back(what);
    }
    else
    {
        std::cout << "neni misto v inventari" << std::endl;
    }
}

void entity::removeFromInventory(unsigned int position)
{
    if (isInInventory(position) == true)
    {
        inventory.erase(inventory.begin() + position);
    }
    else
    {
        std::cout << "toto neni misto v inventari" << std::endl;
    }
}

void entity::useItem(unsigned int position)
//TODO:opravit logiku kodu, aby se 2x nevolalo isInInventory()
{
    if (isInInventory(position) == true)
    {
    item pom = getInventory().at(position);
    switch (pom.getType())
    {
    case 1:
        setHealth(getHealth() + pom.getVaule());
        break;
    case 2:
        setPower(getPower() + pom.getVaule());

    default:
        std::cout << "nic se nedeje" << std::endl;
        break;
    }
    removeFromInventory(position);}
    else{
        std::cout << "toto neni misto v inventari" << std::endl;
    }
}

void entity::showInventory()
{
    if (inventory.size() == 0)
    {
    }
    else
    {
        int i = 0;
        for (item it : getInventory())
        {
            std::cout << i << " je typu " << getInventory().at(i).getType() << ", ";
            i++;
        }
        std::cout<<"\n";
    }
}

bool entity::isInInventory(unsigned int position)
{
    if (position < getInventory().size())
    {
        return true;
    }
    else
    {
        std::cout << "toto neni misto v inventari" << std::endl;
        return false;
    }
}

#include "entity.h"

entity::entity(unsigned int _h, unsigned int _p, inventory _i) : health(_h), power(_p), pocket(_i)
{
}

unsigned int entity::getHealth()
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

inventory entity::getInventory() const
{
    return pocket;
}

bool entity::isAlive()
{
    return (getHealth() > 0) ? true : false;
}
// TODO, udělat to tak, abych se neopakovala 3x+
void entity::health_changer(int _health_modyfier)
{
    int modyfied = int(getPower()) + _health_modyfier;
    if (modyfied < 0)
    {
        setHealth(0); // nelze mít záporne zdravi, w8.
        return;
    }
    setHealth(static_cast<unsigned int>(modyfied));
}

void entity::power_changer(int _power_modyfier)
{
    int modyfied = int(getPower()) + _power_modyfier;
    if (modyfied < 0)
    {
        setPower(0); // nelze mít zápornou sílu, w8.
        return;
    }
    setPower(static_cast<unsigned int>(modyfied));
}
void entity::inventory_size_changer(int _inv_size_modyfier)
{
    int modyfied = int(pocket.get_max_size()) + _inv_size_modyfier;
    if (_inv_size_modyfier < 0)
    { // asi zatim nechci resit, co se stane, kdyz bude plny inventar a snizila by velikost inv
        return;
    }
    pocket.set_max_size(static_cast<unsigned int>(modyfied));
}
// ACHJO
void entity::use_item(int _itemId)
{
    if (pocket.remove_item(_itemId))
    {
        switch (_itemId)
        {
        case SMALLHEAL:
            health_changer(pocket.get_itemtype(SMALLHEAL).get_boost_value());
            break;
        case SMALLPOWERBOOST:
            power_changer(pocket.get_itemtype(SMALLPOWERBOOST).get_boost_value());
            break;
        case SMALLINVENTORYEXPANSION:
            inventory_size_changer(pocket.get_itemtype(SMALLINVENTORYEXPANSION).get_boost_value());
            break;
        default:
            //std::cout << "item is not valid\n";
            break;
        }
    }
}

void entity::vanish_item(unsigned int _itemId)
{
    if(pocket.remove_item(_itemId)) return;
    //idk mozna zbytecna metoda
}

//do budoucnosti se tu muze lepe vypocitavat ze statu attack power, treba jestli implementuju luck, unavu, neco neco
unsigned int entity::entity_attack()
{
    return getPower();
}

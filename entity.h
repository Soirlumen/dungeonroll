#ifndef ENTITY_H
#define ENTITY_H
#include "hlavickovysoubor.h"
#include "inventory.h"

class entity
{
private:
    unsigned int health;
    unsigned int power;
    inventory pocket;
    // unsigned int money;
    // unsigned int energy? nebo to udelat jako nejakou mapu statů? 1,heath; 2,attackpower;3,magicpower????
    void setHealth(int _h);
    void setPower(unsigned int _p);
    inventory getInventory() const;

public:
    unsigned int getHealth();
    unsigned int getPower();
    entity(unsigned int _h, unsigned int _p, inventory _i);
    bool isAlive();
    void health_changer(int _health_modyfier);
    void power_changer(int _power_modyfier);
    void inventory_size_changer(int _inv_size_modyfier);
    void use_item(int _itemId);
    void vanish_item(unsigned int _itemId);
    unsigned int entity_attack();
};

#endif
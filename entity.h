#ifndef ENTITY_H
#define ENTITY_H
#include "hlavickovysoubor.h"
#include "item.h"

class entity
{
private:
    int health,inventorysize;
    unsigned int power;
    std::vector<item> inventory;

public:
    entity(int _h, unsigned int _p,int _is, std::vector<item> _i);
    entity(int _h, unsigned int _p,int _is);
    int getHealth();
    unsigned int getPower();
    void setHealth(int _h);
    void setPower(unsigned int _p);
    bool isAlive();
    std::vector<item> & getInventory();
    void addInInventory(item what);
    void removeFromInventory(unsigned int position);
    void useItem(unsigned int position);
    void showInventory();
    bool isInInventory(unsigned int position);
};

#endif
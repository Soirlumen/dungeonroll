#ifndef ENTITY_H
#define ENTITY_H

#pragma once

class entity
{
private:
 int health;
unsigned int power;
public:
    entity(int _h,unsigned int _p);
     int getHealth();
    unsigned int getPower();
    void setHealth(int _h);
    void setPower(unsigned int _p);
    bool isAlive();
};

#endif
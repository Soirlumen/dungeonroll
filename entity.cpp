#include "entity.h"

entity::entity( int _h, unsigned int _p):health(_h),power(_p){}

 int entity::getHealth()
{
    return health;
}

unsigned int entity::getPower()
{
    return power;
}

void entity::setHealth( int _h)
{
    health=_h;
}

void entity::setPower(unsigned int _p)
{
    power=_p;
}

bool entity::isAlive()
{
            if (getHealth()>0){
            return true;
        }
        return false;
}

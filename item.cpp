#include "item.h"

//type 1 je heal, type 2 je power, uhm, je to implementovaný v entity, upsie

item::item(int _t,  int _v):type(_t),value(_v){}


int item::getVaule()
{
    return value;
}

int item::getType() const
{
    return type;
}


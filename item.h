#ifndef ITEM_H
#define ITEM_H
#include "hlavickovysoubor.h"

class item
{
private:
    int type;
    int value;
public:
    item(int  _t, int _v);
    int getVaule();
    int getType()const;
    ~item() {}
};

#endif
#ifndef INVENTAR_H
#define INVENTAR_H
#include "hlavickovysoubor.h"
#include "item.h"

#pragma once
class item;
class inventar{
private:
unsigned int size;
std::vector<item> libse;

public:
    inventar();
    ~inventar();
};

#endif
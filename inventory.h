#ifndef INVENTORY_H
#define INVENTORY_H
#include "hlavickovysoubor.h"
#pragma once

enum itemID{
    SMALLHEAL=1,
    SMALLPOWERBOOST=2,
    SMALLLUCKBOOST=4,
    SMALLINVENTORYEXPANSION=3
  };
  
class itemtype
{
private:
    const std::string name;
    int boost_value;

public:
    itemtype(const std::string _n, int _bv) : name(_n), boost_value(_bv) {}
    std::string get_name() const
    {
        return name;
    }
    int get_boost_value() const
    {
        return boost_value;
    }
    void set_boost_value(int _newvalue)
    {
        boost_value = _newvalue;
    }
    friend std::ostream &operator<<(std::ostream &os, const itemtype &item)
    {
        os << item.get_name() << " (+ " << item.get_boost_value() << " points)";
        return os;
    }

    ~itemtype() {}
};

class inventory
{
private:
    int max_size;
    const std::map<int, itemtype> myitems;
    std::vector<int> invent;

public:
    inventory(std::map<int, itemtype> _mi, int _s);
    // TODO: konstruktor ktery vezme rovnou nejakym zpusobem i itemy, ale bude to muset být nějak pres postupne nacitani
    // inventory( int _si,  int _st, int _st,std::map<int,itemtype> _mi, std::vector<std::vector< int>> _i);

    // getters setters
    int get_max_size() const;
    void set_max_size(int _newname);
    itemtype get_itemtype(int _id) const;
    unsigned int get_invent_size();

    // prace s inventarem
    bool add_item(int _newitemid);
    bool remove_item(int _removingitemid);
    int find_position_of_item_by_id(int _itemid);
    int find_item_by_position(int _position);
    //int use_item(int _itemid); je treba tato metoda vubec?
    void inventory_cout();
    //TODO: opravit operator<<
    //friend std::ostream &operator<<(std::ostream &os, const inventory &inv);

    // bool metody
    bool is_inventory_full();
    bool is_item_id(int _id);
    bool is_inventory_empty();

    ~inventory();
};

#endif
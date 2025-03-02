#include "inventory.h"

inventory::inventory(std::map<int, itemtype> _mi, int _s) : max_size(_s), myitems(_mi) {}

int inventory::get_max_size() const
{
    return max_size;
}

void inventory::set_max_size(int _newsize)
{
    max_size = _newsize;
}

itemtype inventory::get_itemtype(int _id) const
{
    return myitems.at(_id);
}

unsigned int inventory::get_invent_size()
{
    return invent.size();
}

bool inventory::is_inventory_full()
{
    return (get_invent_size() > get_max_size()) ? true : false;
}

bool inventory::is_item_id(int _id)
{
    return (myitems.find(_id) != myitems.end());
}

bool inventory::is_inventory_empty()
{
    return (get_invent_size() == 0);
}

bool inventory::add_item(int _newitemid)
{
    if (is_inventory_full())
    {
        std::cout << "inventory is full!\n";
        return false;
    }
    if (!is_item_id(_newitemid))
    {
        std::cout << "item does not exist\n";
        return false;
    }
    invent.push_back(_newitemid);
    return true;
}
// tato funkce naopak vrací item na i-té pozici
int inventory::find_item_by_position(int _position)
{
    if (_position > get_invent_size())
    {
        return -1;
    }
    return invent[_position];
}

// tato funkce vrací int hodnotu, která znazornuje pozici, kde ve vektoru se vyskytuje prvni id itemu
int inventory::find_position_of_item_by_id(int _itemid)
{
    if (!is_item_id(_itemid))
    {
        std::cout << "item does not exist\n";
        return -1;
    }
    for (size_t i = 0; i < get_invent_size(); i++)
    {
        if (find_item_by_position(i) == _itemid)
        {
            return i;
        }
    }
    return -2;
}
bool inventory::remove_item(int _removingitemid)
{
    if (find_position_of_item_by_id(_removingitemid) < 0)
    {
        return false;
    }
    invent.erase(invent.begin() + find_position_of_item_by_id(_removingitemid));
    return true;
}
/* int inventory::use_item(int _itemid)
{
    if (remove_item(_itemid))
    {
        return _itemid;
    }
    return -1;
} */

void inventory::inventory_cout()
{
    std::cout << "your inventory: ";
    for (int i = 0; i < get_invent_size(); i++)
    {
        std::cout << i << "-th item is: " << get_itemtype(find_item_by_position(i));
        if (i < get_max_size() - 1)
        {
            std::cout << ", "; // Oddělení čárkou, pokud to není poslední prvek
        }
    }
    std::cout << ".\n";
}

inventory::~inventory()
{
}

// pretizene operatory

/* std::ostream &operator<<(std::ostream &os, const inventory &inv)
{
    os << "Items in your inventory: ";
    int item_id = inv.find_item_by_position(i);
    // Procházejte všechny položky v inventáři
    for (int i = 0; i < inv.get_size(); i++)
    {
        int item_id = inv.find_item_by_position(i);  // Získejte id položky na pozici i
        if (item_id > -1)  // Pokud je položka platná
        {
            os << i << "-th item: " << inv.get_itemtype(item_id);  // Vytiskněte položku
            if (i < inv.get_size() - 1)
            {
                os << ", ";  // Oddělení čárkou, pokud to není poslední prvek
            }
        }
    }

    return os;
}
 */
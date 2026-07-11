#ifndef CART_H
#define CART_H
#include <bits/stdc++.h>
#include "Restraunt.h"
#include "MenuItem.h"
using namespace std;

class Cart
{
private:
    static int nextCartId;
    int cartId;
    Restraunt *restraunt;
    vector<MenuItem *> list;

public:
    Cart()
    {
        restraunt = NULL;
        this->cartId = nextCartId++;
    }

    void addItem(Restraunt *r, MenuItem *mi)
    {
        if (restraunt == NULL)
        {
            this->restraunt = r;
        }
        if (this->restraunt != r)
        {
            this->clear();
        }
        list.push_back(mi);
    }

    Restraunt *getRestraunt()
    {
        return this->restraunt;
    }
    
    vector<MenuItem *> getCart()
    {
        return this->list;
    }

    int total()
    {
        int tot = 0;
        for (auto it : list)
        {
            tot += it->getPrice();
        }
        return tot;
    }

    void clear()
    {
        list.clear();
    }

    bool isEmpty()
    {
        return list.size() == 0;
    }
};
#endif
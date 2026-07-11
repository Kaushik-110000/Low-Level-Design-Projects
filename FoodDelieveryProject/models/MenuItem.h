#ifndef MENUITEM_H
#define MENUITEM_H
#include <bits/stdc++.h>
using std::string;

class MenuItem
{
private:
    static int nextItemCode;
    int code;
    string name;
    double price;

public:
    MenuItem(string name, double price)
    {
        this->code = this->nextItemCode++;
        this->name = name;
        this->price = price;
    }
    int getCode()
    {
        return code;
    }

    string getName()
    {
        return this->name;
    }

    string setName(string name)
    {
        this->name = name;
    }

    double getPrice()
    {
        return this->price;
    }
    void setPrice(double price)
    {
        this->price = price;
    }
};
#endif
#ifndef RESTRAUNT_H
#define RESTRAUNT_H
#include <bits/stdc++.h>
#include "MenuItem.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Restraunt
{
private:
    static int nextRestrauntId;
    int restrauntId;
    string name;
    string location;
    vector<MenuItem *> menu;

public:
    Restraunt(const string &name, const string &location)
    {
        this->restrauntId = nextRestrauntId;
        nextRestrauntId += 1;
        this->name = name;
        this->location = location;
        this->menu = {};
    }

    ~Restraunt()
    {
        cout << "Deleting the restraunt pointer of id : " << restrauntId << " and name : " << name << " at location : " << location << endl;
        for (MenuItem *m : menu)
            delete m;
        menu.clear();
    }

    string getName()
    {
        return name;
    }
    void setName(const string &name)
    {
        this->name = name;
    }
    string getLocation()
    {
        return location;
    }
    void setLocation(const string &location)
    {
        this->location = location;
    }

    void addMenuItem(MenuItem *m)
    {
        this->menu.push_back(m);
    }

    const vector<MenuItem *> &getMenu() const
    {
        return menu;
    }
};

// int Restraunt::nextRestrauntId = 1;
//! this shouldl be used in the cpp file to avoid multiple dec
#endif // RESTRAUNT_H
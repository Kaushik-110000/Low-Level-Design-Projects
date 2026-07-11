#ifndef USER_H
#define USER_H
#include <bits/stdc++.h>
#include "Cart.h"

using namespace std;

class User
{
private:
    static int nextUserId;
    int userId;
    string name;
    string address;
    Cart *cart;

public:
    User(const string &name, const string &address)
    {
        this->userId = nextUserId++;
        this->address = address;
        this->cart = new Cart();
    }

    ~User()
    {
        delete cart;
    }

    string name()
    {
        return this->name;
    }
    void setName(const string &nme)
    {
        this->name = nme;
    }

    string getAddress()
    {
        return this->address;
    }

    void setAddress(const string &a)
    {
        this->address = a;
    }

    Cart *getCart()
    {
        return this->cart;
    }
};
#endif
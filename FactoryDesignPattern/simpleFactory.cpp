#include <bits/stdc++.h>
using namespace std;
class Burger
{
public:
    virtual void prepare() = 0;
};

class BasicBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "We are preparing basic burger" << endl;
    }
};

class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "We are preparing standard burger" << endl;
    }
};
class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "We are preparing premium burger" << endl;
    }
};

class BurgerFactory
{
public:
    Burger *prepareBurger(string type)
    {
        if (type == "basic")
            return new BasicBurger();
        else if (type == "standard")
            return new StandardBurger();
        else
            return new PremiumBurger();
    }
};
int main()
{
    string type = "basic";
    BurgerFactory bf;
    Burger *burger = bf.prepareBurger(type);
    burger->prepare();
}
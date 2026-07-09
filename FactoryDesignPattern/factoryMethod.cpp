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

class BasicWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "We are preparing wheat basic burger" << endl;
    }
};

class StandardWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "We are preparing wheat standard burger" << endl;
    }
};
class PremiumWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "We are preparing wheat premium burger" << endl;
    }
};

class BurgerFactory
{
public:
    virtual Burger *prepareBurger(string type) = 0;
};

class SinghBurger : public BurgerFactory
{
public:
    Burger *prepareBurger(string type) override
    {
        if (type == "basic")
            return new BasicBurger();
        else if (type == "standard")
            return new StandardBurger();
        else
            return new PremiumBurger();
    }
};

class KingBurger : public BurgerFactory
{
public:
    Burger *prepareBurger(string type) override
    {
        if (type == "basic")
            return new BasicWheatBurger();
        else if (type == "standard")
            return new StandardWheatBurger();
        else
            return new PremiumWheatBurger();
    }
};
int main()
{
    string type = "basic";
    BurgerFactory *sbf = new SinghBurger();
    Burger *burger1 = sbf->prepareBurger(type);
    burger1->prepare();

    BurgerFactory *kbf = new KingBurger();
    Burger *burger2 = kbf->prepareBurger(type);
    burger2->prepare();
}
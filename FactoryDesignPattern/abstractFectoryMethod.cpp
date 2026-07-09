#include <bits/stdc++.h>
using namespace std;
class Burger
{
public:
    virtual void prepare() = 0;
};

class GarlicBread
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

class BasicGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "We are preparing basic garlicBread" << endl;
    }
};

class StandardGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "We are preparing standard garlicBread" << endl;
    }
};
class PremiumGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "We are preparing premium garlicBread" << endl;
    }
};

class BasicWheatGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "We are preparing wheat basic garlicBread" << endl;
    }
};

class StandardWheatGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "We are preparing wheat standard garlicBread" << endl;
    }
};
class PremiumWheatGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "We are preparing wheat premium garlicBread" << endl;
    }
};

class MealFactory
{
public:
    virtual Burger *prepareBurger(string type) = 0;
    virtual GarlicBread *prepareBread(string type) = 0;
};

class SinghBurger : public MealFactory
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

    GarlicBread *prepareBread(string type) override
    {
        if (type == "basic")
            return new BasicGarlicBread();
        else if (type == "standard")
            return new StandardGarlicBread();
        else
            return new PremiumGarlicBread();
    }
};

class KingBurger : public MealFactory
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

    GarlicBread *prepareBread(string type) override
    {
        if (type == "basic")
            return new BasicWheatGarlicBread();
        else if (type == "standard")
            return new StandardWheatGarlicBread();
        else
            return new PremiumWheatGarlicBread();
    }
};
int main()
{
    string type = "basic";
    MealFactory *sbf = new SinghBurger();
    Burger *burger1 = sbf->prepareBurger(type);
    GarlicBread *bread1 = sbf->prepareBread(type);
    burger1->prepare();
    bread1->prepare();

    MealFactory *kbf = new KingBurger();
    Burger *burger2 = kbf->prepareBurger(type);
    GarlicBread *bread2 = kbf->prepareBread(type);
    burger2->prepare();
    bread2->prepare();
}
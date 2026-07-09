#include <bits/stdc++.h>
using namespace std;

// all the abstract classes
class Characteristics
{
public:
    virtual ~Characteristics() {}
};
class Talkable : public Characteristics
{
public:
    virtual void talk() = 0;
    virtual ~Talkable() {}
};

class Walkable : public Characteristics
{
public:
    virtual void walk() = 0;
    virtual ~Walkable() {}
};

class Flyable : public Characteristics
{
public:
    virtual void fly() = 0;
    virtual ~Flyable() {}
};

// now extending to make the featuress

class NormalTalk : public Talkable
{
public:
    void talk() override
    {
        cout << "Hi I am talking Normally" << endl;
    }
};

class NoTalk : public Talkable
{
public:
    void talk() override
    {
        cout << "Hi I can not talk" << endl;
    }
};

class NormalWalk : public Walkable
{
public:
    void walk() override
    {
        cout << "Hi I can walk Normally" << endl;
    }
};

class NoWalk : public Walkable
{
public:
    void walk() override
    {
        cout << "Hi I cannot walk" << endl;
    }
};

class NormalFly : public Flyable
{
public:
    void fly() override
    {
        cout << "Hi I can fly Normally" << endl;
    }
};

class NoFly : public Flyable
{
public:
    void fly() override
    {
        cout << "HI I cannot fly" << endl;
    }
};

// robot implementation

class Robot
{
private:
    Talkable *t;
    Walkable *w;
    Flyable *f;

public:
    Robot(Talkable *t, Walkable *w, Flyable *f)
    {
        this->f = f;
        this->w = w;
        this->t = t;
    }

    void fly()
    {
        f->fly();
    }

    void walk()
    {
        w->walk();
    }

    void talk()
    {
        t->talk();
    }

    virtual void Projection() = 0;
};

// myRobot
// this can fly and walk normally but cannot talk

class MyRobot : public Robot
{
public:
    MyRobot(Talkable *t, Walkable *w, Flyable *f) : Robot(t, w, f) {}
    void Projection()
    {
        cout << "This is how I look " << endl;
    }
};

int main()
{
    Robot *r = new MyRobot(
        new NoTalk(),
        new NormalWalk,
        new NormalFly);
    r->fly();
    r->Projection();
    r->talk();
    r->walk();
}
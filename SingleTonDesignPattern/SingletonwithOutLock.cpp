#include <bits/stdc++.h>
using namespace std;

class SingleTon
{
private:
    static SingleTon *instance;
    SingleTon()
    {
        cout << "Creating the object of class SingleTon" << endl;
    }

public:
    static SingleTon *getInstance()
    {
        if (instance == nullptr)
        {
            return instance = new SingleTon();
        }
        else
        {
            return instance;
        }
    }
};

SingleTon *SingleTon::instance = nullptr;

int main()
{
    SingleTon *s1 = SingleTon::getInstance();
    SingleTon *s2 = SingleTon::getInstance();
    cout << (s1 == s2) << endl;
}
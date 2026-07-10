#include <bits/stdc++.h>
using namespace std;

class SingleTon
{
private:
    static SingleTon *instance;
    static mutex mtx;
    SingleTon()
    {
        cout << "Creating the object of class SingleTon" << endl;
    }

public:
    static SingleTon *getInstance()
    {
        return instance;
    }
};

SingleTon* SingleTon::instance = new SingleTon();

int main()
{
    SingleTon *s1 = SingleTon::getInstance();
    SingleTon *s2 = SingleTon::getInstance();
    cout << (s1 == s2) << endl;
}
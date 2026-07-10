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
        if (instance == nullptr)
        {
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr)
                 instance = new SingleTon();
        }
        return instance;
    }
};

SingleTon *SingleTon::instance = nullptr;
mutex SingleTon::mtx;

int main()
{
    SingleTon *s1 = SingleTon::getInstance();
    SingleTon *s2 = SingleTon::getInstance();
    cout << (s1 == s2) << endl;
}
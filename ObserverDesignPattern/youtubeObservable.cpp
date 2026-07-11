#include <bits/stdc++.h>
using namespace std;

class ISubscriber
{
public:
    virtual void update() = 0;
};

class IChannel
{
public:
    virtual void subscribe(ISubscriber *s) = 0;
    virtual void unsubscribe(ISubscriber *s) = 0;
    virtual void notify() = 0;
    virtual string getLatestVideo() = 0;
};

class Channel : public IChannel
{
private:
    set<ISubscriber *> subscribers;
    string name;
    string latestVideo;

    void notify() override
    {
        cout << "\nNotifying all subscribers...\n";

        for (auto it : subscribers)
        {
            it->update();
        }

        cout << "All subscribers notified.\n";
    }

public:
    void subscribe(ISubscriber *s) override
    {
        subscribers.insert(s);
        cout << "A subscriber subscribed.\n";
    }

    void unsubscribe(ISubscriber *s) override
    {
        subscribers.erase(s);
        cout << "A subscriber unsubscribed.\n";
    }

    string getLatestVideo() override
    {
        return latestVideo;
    }

    void addVideo(string video)
    {
        cout << "\nUploading video : " << video << endl;

        latestVideo = video;

        notify();
    }
};

class Subscriber : public ISubscriber
{
private:
    string name;

public:
    IChannel *channel;

    Subscriber(string s, IChannel *ch)
    {
        name = s;
        channel = ch;
    }

    void update() override
    {
        cout << name << " received notification.\n";
        cout << "Latest video is : " << channel->getLatestVideo() << "\n";
    }
};

int main()
{
    Channel channel;

    Subscriber s1("Abhishek", &channel);
    Subscriber s2("Rahul", &channel);
    Subscriber s3("Aman", &channel);

    channel.subscribe(&s1);
    channel.subscribe(&s2);
    channel.subscribe(&s3);

    channel.addVideo("Observer Pattern in C++");

    channel.unsubscribe(&s2);

    channel.addVideo("Strategy Pattern in C++");

    return 0;
}
#ifndef RESTRAUNT_MANAGER_H
#define RESTRAUNT_MANAGER_H

#include <bits/stdc++.h>
#include "Restraunt.h"

using namespace std;

class RestrauntManager
{
private:
    vector<Restraunt *> restraunts;
    // this is a singleton
    static RestrauntManager *instance;
    RestrauntManager() {}

public:
    static RestrauntManager *getInstance()
    {
        return instance;
    }

    void addRestraunt(Restraunt *r)
    {
        restraunts.push_back(r);
    }

    vector<Restraunt *> searchByLocation(string location)
    {
        vector<Restraunt *> list;
        transform(location.begin(), location.end(), location.begin(), ::tolower);

        for (auto it : restraunts)
        {
            string restLoc = it->getLocation();
            transform(restLoc.begin(), restLoc.end(), restLoc.begin(), ::tolower);
            if (location == restLoc)
            {
                list.push_back(it);
            }
        }
        return list;
    }
};
// RestrauntManager *RestrauntManager::instance = NULL;

#endif
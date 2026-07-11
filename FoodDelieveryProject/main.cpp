#include <bits/stdc++.h>
#include "Restraunt.h"
#include "MenuItem.h"
#include "RestrauntManager.h"
#include "User.h"
#include "Cart.h"

using namespace std;

int Restraunt::nextRestrauntId = 1;
int MenuItem::nextItemCode = 1;
RestrauntManager *RestrauntManager::instance = new RestrauntManager();
int User::nextUserId = 1;
int Cart::nextCartId = 1;


int main()
{
}
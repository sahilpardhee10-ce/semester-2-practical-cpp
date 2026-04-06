#include <iostream>
#include <string>
#include "header.h"

using namespace std;

void Inventory::sell()
{
    int sell=0;
    cout << "Enter Quantity to sell" << endl;
    cin >> sell;
    if((sell<=quantity) && sell > 0)
    {
        quantity -= sell;
    }
    else
    {
        cout << "Insufficient Quantity" << endl;
    }
}

void Inventory::add_stock()
{
    long double add=0;
    cout << "Enter Quantity to add" << endl;
    cin >> add;
    if(add > 0)
    {
        quantity += add;
    }
    else
    {
        cout << "Invalid Input!" << endl;
    }
}

void Inventory::view_item_info()
{
    cout << "Item Name: " << name << endl;
    cout << "Item ID: " << id << endl;
    cout << "Item Price: " << price << endl;
    cout << "Item Quantity Available: " << quantity << endl << endl;
}


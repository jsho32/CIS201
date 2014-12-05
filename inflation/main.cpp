/*
Justin A Shores
cis 201
Chapter 2 Project 8
This program will take the cost of an item and the expected inflation percentage and calculate the item's cost in a desired number of years
*/
#include <iostream>

using namespace std;

int main()
{
    double item_cost, inflation_percentage, years_amount;
    int x = -1;
    int y = 0;
    while (x<=3)
    {
    y += 2;
    x += 1;
    }
    cout << y;
    cout << "Enter the current cost of the item in dollars: ";
    cin >> item_cost;

    //get expected inflation percentage from user
    cout << "Enter the expected inflation percentage (i.e. 5.6): ";
    cin >> inflation_percentage;

    //get desired number of years from user
    cout << "Enter the amount of years item will be needed: ";
    cin >> years_amount;

    inflation_percentage = inflation_percentage / 100;
    double years_amount2 = years_amount;

    while (years_amount2 > 0)
    {
        item_cost = item_cost + item_cost * inflation_percentage;
        years_amount2--;
    }
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    //return the cost in desired years to user
    cout << "The cost of the item in " << years_amount << " years will be: $" << item_cost;

    return 0;
}

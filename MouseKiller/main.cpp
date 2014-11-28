/*
Justin A Shores
Cis 201
Chapter 2 Exercise 2
Mouse Killer program
This program will use weights of mouse and humans to calculate the amount of diet soda needed to kill a specified human
*/

#include <iostream>

using namespace std;

int main()
{
    double mouse_weight, human_weight, sweetener_amount;
    char ans;
    double const soda_percentage = 0.001;

    do
    {
    //get mouse weight from user
    cout << "Enter the mouse weight in ounces: ";
    cin >> mouse_weight;

    //get human weight from user
    cout << "Enter the human weight in pounds: ";
    cin >> human_weight;

    //get amount of sweetener that killed mouse from user
    cout << "Enter the amount of sweetener that killed the mouse in ounces: ";
    cin >> sweetener_amount;

    double human_ounces = human_weight * 16;//convert human weight to ounces
    double killing_amount = (sweetener_amount * human_ounces) / mouse_weight;//formula to calculate amount of sweetener needed to kill the human
    double soda_amount = killing_amount / soda_percentage;//using killing amount to calculate amount of diet soda needed

    //return results to user based on their input
    cout << "The total number of units of soda needed to kill the human is: " << soda_amount << endl;

    //ask user to restart program or exit
    cout << "Do you want to repeat the calculation? (press y and then Enter to continue, press n then Enter to exit) ";
    cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    cout << "GOOD-BYE";

    return 0;
}

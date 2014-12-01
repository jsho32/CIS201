/*
Justin A Shores
CIS 201
CH 3 EX 10
This program estimates the growth rate of an organism based on fibinacci numbers
*/

#include <iostream>

using namespace std;

int main()
{
    double pounds, previous_pounds, new_pounds;
    int days, cycles, i;
    char retry;
    //loop to allow program to run again at users request
    do
    {
    //get weight from user
    cout << "Enter the current weight of the green crud (in pounds): ";
    cin >> pounds;
    //get days crud has to grow from user
    cout << "Enter the amount of days in which the crud will have to grow: ";
    cin >> days;
    //set values to be used in algorithm
    previous_pounds = 0;
    cycles = days / 5;
    i = 0;
    //while loop to run algorithm until day limit is reached
    while(i <= (cycles-1))
    {
        new_pounds = previous_pounds + pounds;
        previous_pounds = pounds;
        pounds = new_pounds;
        i++;
    }
    cout << "In " << days << " days, the crud will have reproduced " << cycles << " times, and will weigh " << pounds << "LBS \n" << endl;
    cout << "Would you like to calculate with different parameters? (Y or N): ";
    cin >> retry;
    }
    while(retry == 'Y' || retry == 'y');
    return 0;
}

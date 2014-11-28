/*
Justin A Shores
CIS 201
Leap Year Exercise
This program will take a year from the user and calculate weather or not it is a leap year
*/

#include <iostream>

using namespace std;

int main()
{

    int year;
    //allow program to run until user exits
    do
    {
    //get year from user
    cout << "Please Enter the desired year(Enter -9999 to exit program): ";
    cin >> year;
    //break out of loop if user enters -9999
    if(year==-9999)
    {
        break;
    }

    if((year%400)==0)//if divisible by 400 is leap year
    {
       cout << "The year " << year << " is a leap year" << endl;
    }
    else if((year%100)==0)//if divisible by 100 not leap year
    {
        cout << "Not a leap year SORRY!" << endl;
    }
    else if((year%4)==0)//if divisible by four is leap year
    {
        cout << "The year " << year << " is a leap year" << endl;
    }
    else//everything else is not leap year
    {
        cout << "Not a leap year SORRY!" << endl;
    }

    }
    while(year!=-9999);

    return 0;
}

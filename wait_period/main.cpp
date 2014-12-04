/*
Justin A Shores
CIS 201
Ch 5 Ex 3
This program will request the current time and a wait time from the user and output the time it will be after the wait period,
it will ask the user to repeat the calculation as many times as the user needs
*/
#include <iomanip>
#include <iostream>

using namespace std;

char colon = ':';
void get_wait_time(int& wait_hour, int& wait_min);
void calculate_new_time(int& hour, int& minute, int& wait_hour, int& wait_min, char& mer1, char& mer2);

int main()
{
    int hour, minute, wait_hour, wait_min;
    char mer1, mer2, choice;
    do
    {
    cout << "Please enter the current time in 12 hour notation (i.e. 12:45am): ";
    cin >> hour >> colon >> minute >> mer1 >> mer2;
    get_wait_time(wait_hour, wait_min);
    cout << "The new time will be ";
    calculate_new_time(hour, minute, wait_hour, wait_min, mer1 , mer2);
    cout << "Would like like to run another calculation? (Y or N): ";
    cin >> choice;

    }
    while (choice == 'Y' || choice == 'y');

    return 0;
}

//the following function is a void type function and prompts the user for the waiting time
void get_wait_time(int& wait_hour, int& wait_min)
{
    //get wait time from user
    cout << "Please enter the wait time in 12 hour notation (i.e. 12:45): ";
    cin >> wait_hour >> colon >> wait_min;

    return;
}

//the following function uses the information provided and calculates the time at the end of the wait period and outputs the results in a sentence form
void calculate_new_time(int& hour, int& minute, int& wait_hour, int& wait_min, char& mer1, char& mer2)
{
    int new_hour, new_min;
    char new_mer;
    new_hour = hour + wait_hour;
    new_min = minute + wait_min;
    if(new_min >= 60)
    {
        new_hour += 1;
        new_min -= 60;
    }
    if(new_hour >= 12 && (mer1 == 'A' || mer1 == 'a'))
    {
        new_mer = 'P';
    }
    else if(new_hour >= 12 && (mer1 == 'P' || mer1 == 'p'))
    {
        new_mer = 'A';
    }
    else
    {
        new_mer = mer1;
    }
    if(new_hour > 12)
    {
        new_hour -= 12;
    }

    cout << setfill('0');
    cout << new_hour << colon << setw(2) << new_min << new_mer << mer2 << endl;

    return;
}

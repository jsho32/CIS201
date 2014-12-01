/*
Justin A Shores
CIS 201
Chapter 3 Exercise 3
This program will calculate the cost of a long distance call based on the time, day, and duration of the call
*/

#include <iostream>

using namespace std;

int main()
{
    char day1, day2, choice;
    int duration;
    double cost, time;

    do
    {
    cout << "Please Enter the day the call was made using only the first two letters in the day(i.e. Mo for monday): ";
    cin >> day1 >> day2;
    cout << "Enter the time of day the call was made using a 24-hour clock (i.e. 13.30 for 1.30pm): ";
    cin >> time;
    cout << "How long was the call? (round up to the next whole minute): ";
    cin >> duration;
    if(time > 0 && time <= 24)
    {

    //cost for monday times
    if((day1=='M' || day1=='m') && (day2=='O' || day2=='o'))
    {
        if(time>=8.0 && time<=18.00)
        {
            cost = duration * 0.40; //cost after 8am and b4 6pm
        }
        else
        {
            cost = duration * 0.25; //night cost
        }
    }
    //cost for tuesday
    else if((day1=='T' || day1=='t') && (day2=='U' || day2=='u'))
    {
        if(time>=8.0 && time<=18.00)
        {
            cost = duration * 0.40; //cost after 8am and b4 6pm
        }
        else
        {
            cost = duration * 0.25; //night cost
        }
    }
    //cost for wednesday
    else if((day1=='W' || day1=='w') && (day2=='E' || day2=='e'))
    {
        if(time>=8.0 && time<=18.00)
        {
            cost = duration * 0.40; //cost after 8am and b4 6pm
        }
        else
        {
            cost = duration * 0.25; //night cost
        }
    }
    //cost for thursday
    else if((day1=='T' || day1=='t') && (day2=='H' || day2=='h'))
    {
        if(time>=8.0 && time<=18.00)
        {
            cost = duration * 0.40; //cost after 8am and b4 6pm
        }
        else
        {
            cost = duration * 0.25; //night cost
        }
    }
    //cost for friday
    else if((day1=='F' || day1=='f') && (day2=='R' || day2=='r'))
    {
        if(time>=8.0 && time<=18.00)
        {
            cost = duration * 0.40; //cost after 8am and b4 6pm
        }
        else
        {
            cost = duration * 0.25; //night cost
        }
    }
    //cost for saturday
    else if((day1=='S' || day1=='s') && (day2=='A' || day2=='a'))
    {
        cost = duration * 0.15;//weekend cost
    }
    //cost for sunday
    else if((day1=='S' || day1=='s') && (day2=='U' || day2=='u'))
    {
        cost = duration * 0.15;//weekend cost
    }
    else//entered invalid day format
    {
        cout << "You have entered an invalid day (Please use the format provided)" << endl;
        cost = 0;
    }

    }
    else//invalid time format
    {
        cout << "You have entered an invalid time (Please use the 24-hour clock format)" << endl;
    }

    cout << "The total cost of the call is $" << cost << endl;
    cout << "Would you like to calculate another call? (Y or N): ";
    cin >> choice;

    }
    while(choice=='Y' || choice=='y');

    return 0;
}

/*
Justin A Shores
CIS 201
CH 4 EX 14
This program will take the users weight, intensity level of excersize , and duration of excersize
and calculate the amount of calories needed to maintain the users current body weight
*/

#include <iostream>
#include <cmath>

double metabolic_rate(double pounds);
double physical_activity(double intensity, double pounds, double mins);

using namespace std;

int main()
{
    char choice;
    double weight, activity, duration, calories, consumed;

    //do-while to allow user to restart calculation
    do
    {
        cout << "Please enter your current weight (in pounds): ";
        cin >> weight;
        cout << "Enter the intensity rating of daily exercise: ";
        cin >> activity;
        cout << "Enter the amount of time spent (in minutes) exercising daily: ";
        cin >> duration;
        cout << "Enter the calorie amount in your favorite food: ";
        cin >> calories;
        consumed = calories * 0.1;
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << "You will have to eat "<< (metabolic_rate(weight) + physical_activity(activity, weight, duration) + consumed) / calories << " servings of this food daily to maintain your current weight." << endl;
        //prompt user to run again
        cout << "Would you like to run this calculator again? (Y or N): ";
        cin >> choice;
    }
    while(choice == 'y' || choice == 'Y');

    return 0;
}

//calculate metabolic rate and calories that satisfy
double metabolic_rate(double pounds)
{
    double cal_required;
    double x = pounds / 2.2;
    cal_required = 70 * pow(x, 0.756);
    return cal_required;
}

//calculate physical activity and calories that satisfy
double physical_activity(double intensity, double pounds, double mins)
{
    double cal_required;
    cal_required = 0.0385 * intensity * pounds * mins;
    return cal_required;
}

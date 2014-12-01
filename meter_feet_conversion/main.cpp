/*
Justin A Shores
CIS 201
Ch 5 Ex 8
This program will prompt the user two convert from feet to meters or meters to feet
it will use seperate functions for nearly all sub-tasks, and use if-else statement to decide which conversion to run
it will also allow the user run the conversion calculater as many times as they would like
*/
#include <iostream>

using namespace std;

double feet_to_meters(double feet, double inches);
void output_meters(double meters);
void get_feet(double& feet, double& inches);
double meters_to_feet(double meters, double centimeters);
void get_meters(double& meters, double& centimeters);
void output_feet(double feet);

int main()
{
    char choice;
    int calculation_type;
    do
    {
        double feet, inches, meters, centimeters;
        cout << "Enter '1' to convert feet-to-meters, \nEnter '2' to convert meters-to-feet: ";
        cin >> calculation_type;
        if(calculation_type == 1)
        {
            get_feet(feet, inches);
            feet_to_meters(feet, inches);
            output_meters(feet_to_meters(feet, inches));
        }
        //if user selects to convert from meters to feet
        else if(calculation_type == 2)
        {
            get_meters(meters, centimeters);
            meters_to_feet(meters, centimeters);
            output_feet(meters_to_feet(meters, centimeters));
        }
        //if the user enters an invalid number
        else
        {
            cout << "Invalid selection, Enter only '1' or '2' " << endl;
        }
        cout << "Would you like to try another conversion? (Y or N): ";
        cin >> choice;

    }
    while(choice == 'y' || choice == 'Y');
    return 0;
}

//the following function will convert feet and inches into meters
double feet_to_meters(double feet, double inches)
{
    double meters;
    feet = feet + (inches / 12);
    meters = (feet * 0.3048);
    return meters;
}

//the following function will format and output a string and turn double type meters into int meters and centimeters
void output_meters(double meters)
{
    double centimeters = ((meters - static_cast<int>(meters)) * 100);
    cout << "The distance is: " << static_cast<int>(meters) << " M. " << centimeters << "cm. \n" << endl;
    return;
}

//the following function will prompt the user for the amount of feet and the amount of inches
void get_feet(double& feet, double& inches)
{
    cout << "Please enter the amount of feet only: ";
    cin >> feet;
    cout << "Please enter the amount of inches only: ";
    cin >> inches;

    return;
}

//the folowing function converts meters and centimeters into feet and returns the amount of feet
double meters_to_feet(double meters, double centimeters)
{
    double feet;
    meters = meters + (centimeters / 100);
    feet = (meters * 3.28083);
    return feet;
}

//the following function will get the amount of meters and the amount of centimeters from the user
void get_meters(double& meters, double& centimeters)
{
    cout << "Please enter the amount of meters only: ";
    cin >> meters;
    cout << "Please enter the amount of centimeters only: ";
    cin >> centimeters;

    return;
}

//the following function will output a formatted string and convert a double type feet into int meters and centimeters
void output_feet(double feet)
{
    double inches = ((feet - static_cast<int>(feet)) * 12);
    cout << "The distance is: " << static_cast<int>(feet) << " ft. " << inches << " in. \n"<< endl;
    return;
}

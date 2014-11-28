/*
Justin A Shores
CIS 201
CH 5 EX 6
This program reads in feet and inches and converts to meters and centimeters
*/
#include <iostream>

using namespace std;

double conversion(double feet, double inches);
void output_calculation(double meters);
void get_parameters(double& feet, double& inches);

int main()
{
    char choice;

    do
    {
        double feet, inches;

        get_parameters(feet, inches);
        conversion(feet, inches);
        output_calculation(conversion(feet, inches));

        cout << "Would you like to try another conversion? (Y or N): ";
        cin >> choice;

    }
    while(choice == 'y' || choice == 'Y');

    return 0;
}

double conversion(double feet, double inches)
{
    double meters;
    feet = feet + (inches / 12);
    meters = (feet * 0.3048);
    return meters;
}

void output_calculation(double meters)
{
    cout << "The distance is " << meters << " meters. \n";
    return;
}

void get_parameters(double& feet, double& inches)
{
    cout << "Please enter the distance in feet only: ";
    cin >> feet;

    cout << "Please enter the distance in inches only: ";
    cin >> inches;

    return;
}

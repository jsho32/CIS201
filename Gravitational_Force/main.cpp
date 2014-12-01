/*
Justin A Shores
CIS 201
CH 4 Ex 7
This program will calculate the gravitational force of two masses provided by user
it will use function defining to calculate the force and call the function to return it back to user
*/

#include <iostream>
#include <cmath>

double gravitational_force(double m1, double m2, double dist);
const double G = 6.673 * (pow (10.0, -8.0));

using namespace std;

int main()
{
    char choice;
    double mass1, mass2, distance;

    do
    {
        cout << "Please enter the mass of the first object: ";
        cin >> mass1;
        cout << "Please enter the mass of the second object: ";
        cin >> mass2;
        cout << "Please enter the distance between the two objects: ";
        cin >> distance;
        cout << "The gravitational force between the two objects is: " << gravitational_force(mass1, mass2, distance) << " dynes. " << endl;
        cout << "Would you like to run this program again? (Y or N): ";
        cin >> choice;
    }
    while(choice == 'Y' || choice == 'y');

    return 0;
}

//following function calculates the gravitational force between two objects
double gravitational_force(double m1, double m2, double dist)
{
    double force;
    force = (G *m1 * m2) / (pow(dist, 2.0)); //formula given for gravitational force
    return force;
}

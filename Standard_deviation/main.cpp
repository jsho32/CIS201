/*
Justin A Shores
CIS 201
Ch 7 Ex 4
Standard deviation
This program will read from a file a list of numbers and calculate the standard deviation of the numbers then output
the calculation to the screen, the standard deviation calculation will have its own function and use a partially filled array to meet the specs of the problem
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
void standard_deviation(ifstream& file_name, double arr[], int index);

int main()
{
    ifstream input;
    input.open("stddev.dat");
    double standard_dev[100];
    int numbers;
    standard_deviation(input, standard_dev, numbers);

    return 0;
}

//The following function reads in data from a file and calculates the standard deviation of all the numbers in the file
void standard_deviation(ifstream& file_name, double arr[], int index)
{
    double numbers, sum=0, avg, sum_avg=0, stand_dev;
    index = 0;
    while(file_name >> numbers)
    {
        sum = sum + numbers;
        arr[index] = numbers;
        index++;
    }

    avg = sum / index;
    //for loop allows to calculate algorithm for standard deviation with all numbers stored in the array
    for(int i = 0; i < index; i++)
    {
        arr[i] = pow((arr[i] - avg), 2);
        sum_avg = arr[i] + sum_avg;
    }
    stand_dev = sum_avg / index;
    stand_dev = sqrt(stand_dev);
    //format output to show only four decimal points
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    cout << "The Standard deviation of the numbers in the file is: "<< stand_dev << endl;
}

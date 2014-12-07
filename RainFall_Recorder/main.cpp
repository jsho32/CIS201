/*
Justin A Shores
CIS 201
Rainfall Recorder
This program will read in the data from a file as the amount of rainfall for each month,
it will then compute the avg rainfall for the year and out put a formatted table to a new file
containing the name of the month along with the rainfall for that month and how it differs from the years avg
The program will also create a nice bar graph to show the monthy rainfall and the avg
*/

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
void get_data(ifstream& file_name, double a[], int size);
double compute_avg(double arr[], int size);
void format_to_file(ofstream& file_name, double arr[], int size);
void scale(double arr[], int size);
void print_asterisk(int n, ofstream& file_name);
void graph(double asterisk_count[], int size);
void month_choice(ofstream& file_name, int number);

int main()//***NOTE: the directions were a little unclear but this is how we discussed to do it in class, reads from previous file and writes to current file
{
    double monthly_rain[12];
    int month = 12;
    ifstream rain_data;
    rain_data.open("rainfall_previous.dat");
    ofstream format_data;
    format_data.open("rainfall_current.dat");
    get_data(rain_data, monthly_rain, month);
    format_to_file(format_data, monthly_rain, month);
    cout << "The Program read input from rainfall_previous.dat\n"
         << "and wrote formatted results to rainfall_current.dat\n";

    return 0;
}

//The following function reads in data from a file and stores each peice of data in an array
void get_data(ifstream& file_name, double arr[], int size)
{
    double data;
        for(int i = 0; i < size; i++)
        {
            file_name >> data;
            arr[i] = data;
        }
}

//The following function computes the avg of all numbers read in from the file
double compute_avg(double arr[], int size)
{
    double sum = 0, avg;
    for(int i = 0; i < size; i++)
    {
        sum = arr[i] + sum;
    }
    avg = sum / size;

    return avg;
}

//The following function formats all the data to be written to the new file
void format_to_file(ofstream& file_name, double arr[], int size)
{
    int i;
    file_name.setf(ios::fixed);
    file_name.setf(ios::showpoint);
    file_name.precision(2);
    //output the avg
    file_name << "Average monthly rainfall: "<< compute_avg(arr, size) << endl;
    //output month name and corresponding data
    for(i=0; i<size; i++)
    {
        file_name << "Rainfall in ";
        month_choice(file_name, i);
        file_name << arr[i];
        file_name.setf(ios::showpos);
        file_name << " -- differs from the Avg. by: "<< (arr[i] - compute_avg(arr, size)) << endl;
        file_name.unsetf(ios::showpos);
    }
    scale(arr, size);
    file_name << "\nBAR GRAPH:\n" << "Stars rep. '0.1' each\n" << endl;
    for(i = 0; i < size; i++)
    {
        int stars = static_cast<int>(arr[i]);
        month_choice(file_name, i);
        print_asterisk(stars, file_name);
        file_name << endl;
        file_name << "Avg: ";
        print_asterisk(compute_avg(arr, size), file_name);
        file_name << endl << endl;
    }
}

//The following function will multiply each value stored in an array by ten, to be used in a graph
void scale(double arr[], int size)
{
    for(int index = 0; index < size; index++)
    {
        arr[index] = round(arr[index] * 10);
    }
}

//The following function will print out an asterisk for each whole number value when called
void print_asterisk(int n, ofstream& file_name)
{
    for(int count=1; count <=n; count++)
    {
        file_name << "*";
    }
}

//The following function will take an index variable of an array and assign a corresponding month to that variable
void month_choice(ofstream& file_name, int number)
{
    switch(number)
        {
            case 0: file_name << "JAN: " ;//data for jan is stored in index 0
            break;
            case 1: file_name << "FEB: " ;//feb is in index 1
            break;
            case 2: file_name << "MAR: " ;//mar is index2
            break;
            case 3: file_name << "APR: " ;//you get the idea
            break;
            case 4: file_name << "MAY: " ;
            break;
            case 5: file_name << "JUN: " ;
            break;
            case 6: file_name << "JUL: " ;
            break;
            case 7: file_name << "AUG: " ;
            break;
            case 8: file_name << "SEP: " ;
            break;
            case 9: file_name << "OCT: " ;
            break;
            case 10: file_name << "NOV: " ;
            break;
            case 11: file_name << "DEC: " ;
            break;

        }
}


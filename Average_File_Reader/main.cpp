/*
Justin A Shores
CIS 201
CH 6 Ex 2
This program will read the integers from two seperate files provided by the instructor
and compute the average of all the integers in the files,
The program will then output the average to the screen
*/

#include <iostream>
#include <fstream> // fstream library to allow file reading and writing
//description of function located before function definition
void avg_calculator(std::ifstream& file_name);

using namespace std;

int main()
{
    //intialize the input-file streams needed to read two files
    ifstream first_file, second_file;
    //set first input stream to read input1.dat
    first_file.open("input1.dat");
    //set second input stream to read input2.dat
    second_file.open("input2.dat");
    //format output string
    cout << "The average of the numbers contained in the file 'input1.dat' is: ";
    //call the average calculating function using input1.dat as the parameter
    avg_calculator(first_file);
    cout << "The average of the numbers contained in the file 'input2.dat' is: ";
    //call average calculating function using input2.dat as parameter
    avg_calculator(second_file);
    //end program
    return 0;
}
//The following function uses the file that is being read and calculates the average of the numbers contained in the file
void avg_calculator(std::ifstream& file_name)
{
    double next, sum=0, avg;
    int count=0;//to count how many numbers are in the file
    //while loop allows us to read each number individually and count the amount of numbers
    while(file_name >> next)
    {
        sum = sum + next;//sum = the sum of each previous number + the next number until loop ends
        count++;//adds one everytime a new number is read
    }
    avg = sum / count;//average equals the sum of all the numbers divided by the total number of numbers
    cout << avg << endl; //prints out the avg to the screen

}

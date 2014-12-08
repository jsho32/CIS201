/*
Justin A Shores
CIS 201
Midterm project
10-15-13
This program will have a fibonacci number calculating function.
The function will take an integer as a parameter which is the fibonacci number to calculate, and return the fibonacci number.
Then this function will calculate the sum of every fibonacci number that is divisible by 3 or 5.
It will do this for all fibonacci numbers less than 4,000,000.
*/
#include <iostream>

using namespace std;
//descriptions of functions located above function definition
void get_int(int& fib_place);
void return_fibonacci(int& fibbonacci);

int main()
{
    int fib_place;
    char choice;
    do
    {
        get_int(fib_place);
        return_fibonacci(fib_place);
        cout << "\nWould you like to run the program again? (Y or N): ";
        cin >> choice;
    }
    while(choice =='y' || choice == 'Y');
    return 0;
}

//the following function will prompt the user for a fibonacci place holder position
void get_int(int& fib_place)
{
    cout << "Please enter the place number (integers only), \nof the fibbonacci number you would like calculated: ";
    cin >> fib_place;
}

//the following function will take an integer as its parameter, and calculate the fibonacci number that lies in the integers place position
//it will also add together all the fibonacci numbers that are divisible by 3 or 5
//then format and return the information back to the screen
void return_fibonacci(int& fib_number)
{
    int fib1 = 0, fib2 = 1, fib3, sum_fib=0;
    if(fib_number > 1)
    {
        for(int place=1; place<fib_number; place++)
        {
            fib3 = fib1 + fib2;
            fib1 = fib2;
            fib2 = fib3;
            if((fib3 % 3) ==0 || (fib3 % 5) == 0)
            {
                sum_fib = sum_fib + fib3;
            }
        }
    }
    else if(fib_number = 1)
    {
        fib3 = 1;
    }
    if(fib3 < 4000000)
    {
        cout << "\nThe fibonacci number in place holder position '" << fib_number << "' is: " << fib3 << endl;
        cout << "\nThe sum of all the fibonacci numbers that are divisible by '3' or '5', \nup to position '" << fib_number << "' is: " << sum_fib << endl;;
    }
    else
    {
        cout << "The fibonacci number is to large it is over 4,000,000 sorry!" << endl;
    }
}

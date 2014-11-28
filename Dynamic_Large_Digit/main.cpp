/*
Justin Shores
CIS201
Ch 9 Ex 1
This program is a revision of the large digit adding problem from ch. 7
It will use dynamic arrays to store the integers to be added
as well as allowing for an arbitrary number of digits rather than capping it at 20 like ch 7's version
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
void get_numbers(char **numbers);
void add_numbers(char ** numbers);
char *numbers[2];
int size1, size2, size3;

int main()
{
    char choice;

    cout << "Large Digit Adding:\nThis program will add to two large integers together" << endl;
    //do while to allow multiple additions
    do
    {
        get_numbers(numbers);
        add_numbers(numbers);
        cout << "\nWould you like to perform another addition? (Y or N): ";
        cin >> choice;
    }
    while(choice == 'y' || choice == 'Y');

    return 0;
}

//the following function prompts user for two integers to be added together,
//it will take in the numbers as a string, then convert to chars and store
//in our global dynamic array
void get_numbers(char **numbers)
{
    string number1, number2;
    //prompt for numbers
    cout << "Please enter first number: ";
    cin >> number1;
    cout << "Please enter second number: ";
    cin >> number2;

    size1 = number1.size();
    size2 = number2.size();

    numbers[0] = new char[size1];
    numbers[1] = new char[size2];

    strcpy(numbers[0], number1.c_str());
    strcpy(numbers[1], number2.c_str());

}

//the following function will add the two numbers that are stored in the
//two array indeces, store the added number in a temp array,
//then format and return results to user
void add_numbers(char **numbers)
{
    if(size1 >= size2)
        size3 = size1;
    else
        size3 = size2;

    int temp[size3],j = 0;//initialize temp array, j will be used as temp array index

    for(int i = size3; i > 0; i--)
    {
        if((size1 - i >= 0) && (size2 - i >= 0))
        {
            temp[j] = (numbers[0][size1-i]-48) + (numbers[1][size2-i]-48);
        }
        else if((size1 - i) < 0)
        {
            temp[j] = (numbers[1][size2-i]-48);
        }
        else if((size2 - i) < 0)
        {
            temp[j] = (numbers[0][size1-i]-48);
        }
        j++;
    }

    for(int i = size3-1; i > 0; i--)
    {
        if ((temp[i]) > 9)
        {
            temp[i-1] = temp[i-1]+1;
            temp[i] -= 10;
        }
    }
    cout << "\nThe Solution is: ";
    for(int i = 0; i < size3; i++)
        cout << temp[i];

    cout << endl;
}

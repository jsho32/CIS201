/*
Justin A Shores
CIS 201
This program reads in two strings of numbers as type char, stores the numbers in a partially filled array
then converts the array to type int
then adds the two large numbers together
and outputs the sum to the screen
*/
#include <iostream>

using namespace std;
void get_numbers(char[], char[], int);
void store_numbers(char[], char[],int[][2], int);
void reverse_order(int[][2], int);
void digit_adding(int[], int[][2], int);
void return_results(int[], int);
int array_size = 20;
int size;

int main()
{
    char num1[array_size];
    char num2[array_size];
    int storage[array_size][2];
    int results[array_size];
    char choice;

    cout << "Large Digit Adding: \nThis program will add two numbers less than 20 digits in length" << endl;

    do
    {
        get_numbers(num1, num2, array_size);
        store_numbers(num1, num2,storage, array_size);
        reverse_order(storage, array_size);
        digit_adding(results, storage, array_size);
        return_results(results, array_size);
        cout << "\nWould you like to perform another addition? (Y or N): ";
        cin >> choice;
    }
    while(choice == 'y' || choice == 'Y');

    return 0;
}

//function gets the strings of char from the user
void get_numbers(char arr1[], char arr2[], int size)
{
    cout << "Note: enter numbers of the same length(i.e. 200 + 002 = 202)\n";
    cout << "\nPlease enter the first number: ";
    cin >> arr1;
    cout << "Please enter the second number: ";
    cin >> arr2;
}

//function takes in two char arrays and converts to one two dimensional int array
void store_numbers(char arr1[], char arr2[],int arr[][2], int size)
{
    int i = 0;
    char next;
    while(arr1[i] << next)
    {
        arr[i][0] = arr1[i] - 48;
        i++;
    }
    for(i; i < size; i++)
    {
        arr[i][0] = -1;
    }
    int c = 0;
    while(arr2[c] << next)
    {
         arr[c][1] = arr2[c] - 48;
         c++;
    }
    for(c; c < size; c++)
    {
        arr[c][1] = -1;
    }

}

//function reverses the order of array to make adding easier
void reverse_order(int arr[][2], int size)
{
    int temp[size][2], index = 0;
    for(int i = size-1; i >= 0; i--)
    {
        temp[index][0] = arr[i][0];
        temp[index][1] = arr[i][1];
        index++;
    }
    for(int i = 0; i < size; i++)
    {
        arr[i][0] = temp[i][0];
        arr[i][1] = temp[i][1];
    }
}

//function adds the contents of array one digit at a time and stores in a final resulting array
void digit_adding(int final[], int arr[][2], int size)
{
    for(int i = 0; i < size; i++)
    {
        if((arr[i][0] > -1) && (arr[i][1] > -1))
        {
            final[i] = arr[i][0] + arr[i][1];
        }
        else if((arr[i][0] == -1) && (arr[i][1] != -1))
        {
            final[i] = arr[i][1];
        }
        else if((arr[i][1] == -1) && (arr[i][0] != -1))
        {
            final[i] = arr[i][0];
        }
        else
        {
            final[i] = -1;
        }

        if(i < size-1)
        {
            if(final[i] > 9)
            {
                arr[i+1][0] = arr[i+1][0] +1;
                final[i] = final[i] - 10;
            }
        }
    }
}

//the following function formats and returns the results back to the screen
void return_results(int arr[], int size)
{
    int i = 0, index = size-1;
    while(arr[i] < 0)
    {
        i++;
    }
    int count = size - i;
    int temp[count];
    for(i = 0; i < count; i++)
    {
        temp[i] =  arr[index];
        index--;
    }
    cout << "The sum of the two numbers is: ";
    for(int i = 0; i < count; i++)
    {
        cout << temp[i];
    }
    cout << endl;
}

/*
Justin Shores
CIS 201
Computer Lab Inventory Problem
CH 9 EX 5
This program will create a display that shows who is logged on to what computer in what lab
as well as provide the administrator with a search tool to display where a particular person is logged on
it will use a fixed array to store lab numbers each lab number will point to a dynamic array for lab stations
*/

#include <iostream>
#include <cstring>

using namespace std;

void create_empty_lab(char ***labs);
void login_menu(char ***labs);
void print_to_screen(char ***labs);
void logout_menu(char ***labs);
void search_user(char ***labs);

int main()
{
    int choice;
    char **labs[4];
    labs[0] = new char*[5], labs[1] = new char*[6], labs[2] = new char*[4], labs[3] = new char*[3];
    cout << "Welcome to the Computer Lab Main Menu!" << endl;
    create_empty_lab(labs);
    do
    {
        //promt user for option selection
        cout << "\nWhat would you like to do? \nType 1 for login, 2 for logout, 3 for search, and 4 to exit" << endl;
        cout << "Enter your selection now: ";
        cin >> choice;

        if(choice == 1)//log in option
        {
            login_menu(labs);
            print_to_screen(labs);
        }
        else if(choice == 2)//log out option
        {
            logout_menu(labs);
            print_to_screen(labs);
        }
        else if(choice == 3)//search option
        {
            search_user(labs);
        }
        else if(choice == 4)//exit option
        {
            return 0;
        }
        else //invalid option
        {
            cout << "Invalid number only numbers 1-4 are accepted" << endl;
        }
    }
    while(choice != 4);//repeat loop while exit option not chosen
    return 0;//return successful as safety measure
}

//the following function will fill all arrays with empty users
void create_empty_lab(char ***labs)
{
    for(int i=0; i < 5; i++)//lab1
       labs[0][i] = "Empty";
   for(int i=0; i < 6; i++)//lab2
       labs[1][i] = "Empty";
   for(int i=0; i < 4; i++)//lab3
       labs[2][i] = "Empty";
   for(int i=0; i < 3; i++)//lab4
       labs[3][i] = "Empty";
}

//the following function creates the login menu and sets the users id number to the desired lab and station locations
void login_menu(char ***labs)
{
    char *id = new char[6];
    int lab, station;
    //prompt user for login info
    cout << "\nLog IN Menu: " << endl;
    cout << "Enter 5 digit ID number: ";
    cin >> id;
    cout << "Enter Lab number: ";
    cin >> lab;

    if(lab > 0 && lab < 5)//only continue if valid lab number was selected
    {
        cout << "Enter Station number: ";
        cin >> station;
    }
    else
    {
        cout << "\nInvalid lab number! labs consist of 1 - 4" << endl;
    }
    //check to make sure valid station number was chosen
    if(lab == 1 && (station < 6 && station > 0))//lab1 has 5 stations 1 - 5
        labs[lab-1][station-1] = id;
    else if(lab == 2 && (station < 7 && station > 0))//lab2 1 - 6
        labs[lab-1][station-1] = id;
    else if(lab == 3 && (station < 5 && station > 0))//lab3 1 - 4
        labs[lab-1][station-1] = id;
    else if(lab == 4 && (station < 4 && station > 0))//lab4 1 - 3
        labs[lab-1][station-1] = id;
    else
        cout << "\nInvalid Station number!" << endl;
}

//the following function will format and print the current lab usage to the screen
void print_to_screen(char ***labs)
{
    cout << "\nCurrent Lab Usage: " << endl;
    cout << "LABS:       " << " STATIONS: " << endl;
    cout << "\nLab 1:    ";
    for(int i = 0; i < 5; i++)//lab1 five-stations
    {
        cout << i+1 << ": " << labs[0][i] << " ";
    }
    cout << "\nLab 2:    ";
    for(int i = 0; i < 6; i++)//lab2 six-stations
    {
        cout << i+1 << ": " << labs[1][i] << " ";
    }
    cout << "\nLab 3:    ";
    for(int i = 0; i < 4; i++)//lab3 four-stations
    {
        cout << i+1 << ": " << labs[2][i] << " ";
    }
    cout << "\nLab 4:    ";
    for(int i = 0; i < 3; i++)//lab4 three-stations
    {
        cout << i+1 << ": " << labs[3][i] << " ";
    }
    cout << endl;
}

//the following function creates the log out menu and logs out the users id number from the lab and station they are currently logged on to
void logout_menu(char ***labs)
{
    char *id = new char[6];
    int x = 0;
    cout << "\nLog OUT Menu: " << endl;
    cout << "Enter 5 digit ID number: ";
    cin >> id;

    for(int i = 0; i < 5; i++)//check five stations in lab 1
    {
        if(strcmp(labs[0][i], id))//if current position matches log off info
        {
            labs[0][i] = labs[0][i];
            x = 1;
        }
        else//if no match
        {
            labs[0][i] = "Empty";
        }
    }
    for(int i = 0; i < 6; i++)//check 6 stations in lab 2
    {
        if(strcmp(labs[0][i], id))
        {
            labs[1][i] = labs[0][i];
            x = 1;
        }
        else//if no match
        {
            labs[1][i] = "Empty";
        }
    }
    for(int i = 0; i < 4; i++)//check 4 stations in lab 3
    {
        if(strcmp(labs[0][i], id))
        {
            labs[2][i] = labs[0][i];
            x = 1;
        }
        else//if no match
        {
            labs[2][i] = "Empty";
        }
    }
    for(int i = 0; i < 3; i++)//check 3 stations in lab 4
    {
        if(strcmp(labs[0][i], id))
        {
            labs[3][i] = labs[0][i];
            x = 1;
        }
        else//if no match
        {
            labs[3][i] = "Empty";
        }
    }
    if(x == 1)//if x was set to 1, user was found
        cout << "You are now logged off" << endl;
    else
        cout << "User " << id << " is not currently logged on, cannot log off!" << endl;
}

//the following function will search for a user that is currently logged on and display where they are located
void search_user(char ***labs)
{
    char *id = new char[6], id2[6];
    int x = 0, y = 0;
    cout << "\nSearch for User:" << endl;
    cout << "Enter 5 digit ID number of user you are looking for: ";
    cin >> id;

    for(int i = 0; i < 5; i++)//lab 1 - 5 stations
    {
        if(*labs[0][i] == *id)//if dereferances match
        {
            x = i + 1;
            y = 1;
        }
    }

    for(int i = 0; i < 6; i++)//lab 2 - 6 stations
    {
        if(*labs[1][i] == *id)
        {
            x = i + 1;
            y = 2;
        }
    }
    for(int i = 0; i < 4; i++)//lab 3 - 4 stations
    {
        if(*labs[2][i] == *id)
        {
            x = i + 1;
            y = 3;
        }
    }
    for(int i = 0; i < 3; i++)//lab 4 - 3 stations
    {
        if(*labs[3][i] == *id)
        {
            x = i + 1;
            y = 4;
        }
    }
    if(x != 0 && y != 0)//if user was found
    {
        cout << "User number '" << id << "' is located in Lab " << y << " at Station " << x << endl;
    }
    else
    {
        cout << "User number '" << id << "' was not found!" << endl;
    }

}

/*
Justin A Shores
Cis 201
Rock Paper Scissors
This program will simulate the classic game
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    int choice;
    char option;
    const int scale = 3;
    const int shift = 1;
    //allow for rematch with do-while loop
    do
    {
    int random_number = random() % scale + shift; 
    cout << "Lets play Rock Paper Scissors \n"
    << "Enter - 1 for ROCK - 2 for PAPER - 3 for SCISSORS " << endl;
    cin >> choice;
    cout << "You chose " << choice << endl;
    cout << "Computer chose " << random_number << endl;
    //all cases in which user loses
    if((choice == 1 && random_number == 2) || (choice == 2 && random_number == 3) || (choice == 3 && random_number == 1))
    {
        cout << "YOU LOSE!!!" << endl;
    }
    //allcases user wins
    else if((choice == 2 && random_number == 1) || (choice == 3 && random_number == 2) || (choice == 1 && random_number == 3))
    {
        cout << "YOU WIN!!!!!!!" << endl;
    }
    //in case of tie
    else if(choice == random_number)
    {
        cout << "IT's A TIE!!!" << endl;
    }
    //if user enters invalid number
    else
    {
        cout << "bad number! use only numbers 1-3" << endl;
    }
    //ask to play again
    cout << "Would you like to play again? (Y or N): " << endl;
    cin >> option;

    }
    while(option == 'Y' || option == 'y');//loop again if user selects yes

    return 0;
}

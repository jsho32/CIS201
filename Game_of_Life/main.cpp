/*
Justin Shores
CIS 201
Game of Life
This program will implement conway's classic Game of Life
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <cscreen>

using namespace std;

const int row_size = 80;
const int col_size = 25;
void clear_board(char[row_size][col_size]);
void fill_starting_board(char[row_size][col_size], int);
void run_game(char[row_size][col_size], int);

int main()
{
    char choice, start;
    int population, generations;
    char board[row_size][col_size];
    cout << "Conway's Game of Life" << endl;
    do
    {
        //prompt user for starting population size
        cout << "Enter a starting number for population (recomended 75-150): ";
        cin >> population;
        //prompt user for amount of generations game will run
        cout << "Enter the number of generations the program will run (recommended 50-100): ";
        cin >> generations;
        system("clear");//clears the screan on unix systems only
        clear_board(board);
        fill_starting_board(board, population);
        cout << "This is the random placement of your population, Start Life? (Y or N): ";
        cin >> start;
        if(start == 'y' || start == 'Y')
        {
            run_game(board, generations);
        }
        cout << "Would you like to run the game again? (Y or N): ";
        cin >> choice;
        system("clear");//unix only
    }
    while(choice == 'y' || choice == 'Y');
    return 0;
}

//the following function will create an empty game board by creating a two dimensional array and filling it with blank spaces
void clear_board(char arr[row_size][col_size])
{
    for(int j = 0; j < col_size; j++)
    {
        for(int i = 0; i < row_size; i++)
        {
            arr[i][j] = ' ';
        }
    }

}

//the following function will randomly place '*' to represent live cells based on settings privided by the user
void fill_starting_board(char arr[row_size][col_size], int pop)
{
    srand(time(0));
    int random_row, random_col;
    for(int i = 0; i < pop; i++)
    {
        //generate random numbers to be used as indexes in two dimensional array
        random_row = random() % row_size/2 + 20;
        random_col = random() % col_size/2 + 7;

        if(arr[random_row][random_col] == '*')
        {
            i--;
        }
        else
        {
            arr[random_row][random_col] = '*';//fill randomly generated space with *
        }
    }
    //print randomly generated poulation to screen...
    for(int j = 0; j < col_size; j++)
    {
        for(int i = 0; i < row_size; i++)
        {
            cout << arr[i][j];
        }
        cout << endl;//after each row is complete end line to continue to next col space
    }
    cout << endl;
}

//the following function will run the game by checking each cells neighbors for life and replacing the current cell
//with life or emptying cell based on rules of the game, until generation setting is met
void run_game(char arr[row_size][col_size], int gen)
{
    for(int iterations = 0; iterations < gen; iterations++)
    {
        system("clear");
        for(int j = 0; j < col_size; j++)
        {
            for(int i = 0; i < row_size; i++)
            {
                int count = 0;

                if(i == 0 && j == 0)//represents top left corner of board
                {
                    if(arr[i+1][j] == '*') count++;
                    if(arr[i+1][j+1] == '*') count++;//checks surrounding cells for life
                    if(arr[i][j+1] == '*') count++;
                }
                else if(i == 0 && (j > 0 && j < col_size -1))//represents left edge of board (no corners)
                {
                    if(arr[i+1][j-1] == '*') count++;
                    if(arr[i+1][j] == '*') count++;
                    if(arr[i+1][j+1] == '*') count++;//check surrounding cells
                    if(arr[i][j-1] == '*') count++;
                    if(arr[i][j+1] == '*') count++;
                }
                else if(j == 0 && (i > 0 && i < row_size -1))//top edge of board
                {
                    if(arr[i-1][j] == '*') count++;
                    if(arr[i-1][j+1] == '*') count++;
                    if(arr[i][j+1] == '*') count++;//check surrounding cells
                    if(arr[i+1][j+1] == '*') count++;
                    if(arr[i+1][j] == '*') count++;
                }
                else if(i == row_size-1 && (j > 0 && j < col_size -1))//right edge of board
                {
                    if(arr[i-1][j] == '*') count++;
                    if(arr[i][j+1] == '*') count++;
                    if(arr[i-1][j-1] == '*') count++;
                    if(arr[i][j-1] == '*') count++;
                    if(arr[i-1][j+1] == '*') count++;
                }
                else if(j == col_size-1 && (i > 0 && i < row_size -1))//bottom edge of board
                {
                    if(arr[i-1][j-1] == '*') count++;
                    if(arr[i-1][j] == '*') count++;
                    if(arr[i][j-1] == '*') count++;
                    if(arr[i+1][j-1] == '*') count++;
                    if(arr[i+1][j] == '*') count++;
                }
                else if(i == row_size-1 && j == col_size -1)//bottom right corner of board
                {
                    if(arr[i-1][j-1] == '*') count++;
                    if(arr[i-1][j] == '*') count++;
                    if(arr[i][j-1] == '*') count++;
                }
                else if(i == row_size-1 && j == 0)//top right corner
                {
                    if(arr[i-1][j] == '*') count++;
                    if(arr[i-1][j+1] == '*') count++;
                    if(arr[i][j+1] == '*') count++;
                }
                else if(i == 0 && j == col_size-1)//bottom left of board
                {
                    if(arr[i][j-1] == '*') count++;
                    if(arr[i+1][j-1] == '*') count++;
                    if(arr[i+1][j] == '*') count++;
                }
                else//all remaining cells should not be along any edge of board
                {
                    if(arr[i-1][j-1] == '*') count++;
                    if(arr[i-1][j] == '*') count++;
                    if(arr[i-1][j+1] == '*') count++;//check all neighbors
                    if(arr[i][j-1] == '*') count++;
                    if(arr[i][j+1] == '*') count++;
                    if(arr[i+1][j-1] == '*') count++;
                    if(arr[i+1][j] == '*') count++;
                    if(arr[i+1][j+1] == '*') count++;
                }

                if(arr[i][j] == '*')//if the current cell is alive
                {
                    if(count == 2 || count == 3)//and it has 2 or 3 live neighbors
                        arr[i][j] = '*';//then the cell remains alive

                    else if(count < 2 || count > 3)//otherwise...
                        arr[i][j] = ' ';//the cell becomes dead
                }
                else if(arr[i][j] == ' ')//if the current cell is dead
                {
                    if(count == 3)//and it has exactly 3 neighbors
                        arr[i][j] = '*';//then the cell become alive

                    else if(count != 3)//otherwise...
                        arr[i][j] = ' ';//cell remains dead
                }
                cout << arr[i][j];
            }
        cout << endl;
    }
    cout << endl;
    for(int d = 0; d < 50000000; d++){}
    }
}

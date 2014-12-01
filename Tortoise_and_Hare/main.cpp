/*
Justin Shores
Final Project
The Tortoise and the Hare

Our contenders begin the race at "square 1" of 70 squares. Each square represents a possible position along the race course.
The finish line is at square 70. The first contender to reach or pass square 70 is rewarded with a pail of fresh carrots and lettuce.
The course weaves its way up the side of a slippery mountain, so occasionally the contenders lose ground.there is a clock that ticks once per second.
Use variables to keep track of the positions of the animals (ie., position numbers are 1-70). Start each animal at position 1 (i.s., the "starting gate").
If an animal slips left before square 1, move the animal back to square 1
Generate the percentages in the preceding table by producing a random integer i in the range 1<= i <= 10. For the tortoise, perform a "fast plod"
when 1 <=i <= 5, a "slip" when 6 <=i <=7 or a "slow plod" when 8<=i<=10. Use a similar technique to move the hare.

Begin the race by printing

BANG!!!!!
AND THEY'RE OFF !!!!

For each tick of the click (i.e., each repetition of a loop), print a 70-position line showing the letter T in the toroise's position
 and the letter H in the hare's position. Occasionally, the contenders land on the same square.
 In this case, the tortoise bites the hare, and your program should print OUCH!!! beginning at that position.
 All print positions other than the T, the H or the OUCH!!! (in case of a tie) should be blank.

After printing each line, test if either animal has reached or passed square 70. If so, print the winner and terminate the simulation.
If the tortoise wins, print TORTOISE WINS!!! YAY!!! If the hare wins, print Hare wins. Yawn. . .
If both animals win on the same clock tick, you may want to favor the tortoise (the "underdog"), or you may want to print It's a tie.
If neither animal wins, perform the loop again to simulate the next tick of the clock.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
const int RACE_END = 70;
int tortoise(int, int);
int bunny(int, int);
void display_race(int,int);
int turtle;

int main()
{
    srand(time(0));
    int Tposition = 0, Hposition = 0;
    cout << "Bang!!! \nAnd They're OFF!!!" << endl;
    while(Tposition < 70 && Hposition < 70)
    {
        int hare = 1 + rand() % 10;
        int tort = 1 + rand() % 10;

        Tposition = tortoise(tort, Tposition);
        Hposition = bunny(hare, Hposition);
        display_race(Hposition, Tposition);
        for(int i = 0; i < 100000000; i++){}//empty for loop to allow user to see race unfold
    }
    if(Hposition > Tposition)//if hare wins
        cout << "\nHare Wins... YAWN";
    else if(Tposition > Hposition)//if toroise wins
        cout << "\nTORTOISE WINS! YAY!!!!";
    else//if tie
        cout << "It's A TIE!";
    return 0;
}

//tortoise function sets the new position of the tortoise after it moves based on specs
int tortoise(int moves, int pos)
{
    int move;
    if(moves >= 1 && moves <=5)//fast plod
        move = 3;
    else if(moves > 5 && moves < 8)//big slip
        move = -6;
    else if(moves >= 8 && moves <= 10)//slow plod
        move = 1;

    pos = pos + move;
    if(pos < 0)
        pos = 0;
    if(pos > 70)
        pos = 70;

    return pos;
}

//bunny function sets the new position of the hare after it moves based on specs
int bunny(int moves, int pos)
{
    int move;
    if(moves >= 1 && moves < 3)//sleep
        move = 0;
    if(moves >= 3 && moves < 5)//big hop
        move = 9;
    if(moves >= 5 && moves < 6)//big slip
        move = -12;
    if(moves >= 6 && moves < 9)//small hop
        move = 1;
    if(moves >= 9 && moves <= 10)//small slip
        move = -2;

    pos = pos + move;//new position by adding old position to move
    if(pos < 0)
        pos = 0;
    if(pos > 70)
        pos = 70;
    return pos;
}

//display function prints the racers position to the screen using io manipulations
void display_race(int bunny, int shelly)
{
    for(int i = 0; i < 10; i++)
    {
        cout << endl;
    }
    if(bunny > shelly)
    {
        cout << "Hare takes the lead!" << endl;
    }
    else if(shelly > bunny)
    {
        cout << "Tortoise takes the lead!!!!!" << endl;
    }
    for(int i = 0; i < 70; i++)
    {
        cout << "-";
    }
    cout << endl;
    if(bunny < shelly)//if tortoise is in the lead
    {
        cout << setw(bunny) << "H";
        cout << setw(shelly-bunny) << "T";
    }
    else if(shelly < bunny)//if hare is winning
    {
        cout << setw(shelly) << "T";
        cout << setw(bunny-shelly) << "H";
    }
    else//if tied
    {
        cout << setw(shelly) << "OUCH!";//tortoise bites hare
    }
    cout << endl;
    for(int i = 0; i < 70; i++)
    {
        cout << "-";
    }
    for(int i = 0; i < 11; i++)
    {
        cout << endl;
    }

    return;
}

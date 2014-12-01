/*
Justin A Shores
CIS 201
CH6 EX 7
This program will read integers from two files containing only integers in ascending order,
it will then copy all the integers from both files and write them to a third file and sort them in ascending order
*/

#include <iostream>
#include <fstream>

using namespace std;

void write_to_file(ifstream& file_name1, ifstream& file_name2, ofstream& output_file);

int main()
{
    ifstream input1, input2;
    ofstream output1, output2;

    input1.open("input1.dat");
    input2.open("input2.dat");
    output1.open("File1.dat");
    write_to_file(input1, input2, output1);
    input1.close();
    input2.close();
    output1.close();

    return 0;
}

//The following function will read input from two files and write everything that is read into a third file arranging all numbers in ascending order
void write_to_file(ifstream& file_name1, ifstream& file_name2, ofstream& output_file)
{
    double next1, next2;

    file_name1 >> next1;
    file_name2 >> next2;

    while(! file_name1.eof())
    {
        if(next1 < next2)
        {                                   
            output_file << next1 << endl;
            file_name1 >> next1;
        }
        else
        {
            output_file << next2 << endl;
            file_name2 >> next2;
        }
    }
    while(! file_name2.eof())
    {
        output_file << next2 << endl;
        file_name2 >> next2;
    }

}

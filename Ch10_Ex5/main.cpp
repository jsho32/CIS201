/*
Justin Shores
CIS 201
Ch 10 Ex 5
This program will define a class type named CounterType
The class will contain a default constructor setting the value of counter to zero,
a constructor with one argument to set counter to the value of its argument,
member functions to increase and decrease counter by one,
and member functions to return current counter and output count to a stream
*my test program will open a file read in the integers from the file,
*then call the increase member function for numbers greater than 0
*and the decrease member function for all other numbers.
*/
#include <iostream>
#include <fstream>

using namespace std;

class CounterType
{
public:
    CounterType();
    void set_counter(int);
    void increase_count();
    void decrease_count();
    int return_count();
    void output_count(ostream&);
private:
    int counter;
};

//test program
int main()
{
    int start, next;

    ifstream input;
    input.open("test_file.txt");
    CounterType num_counter;
    //get starting number
    cout << "Enter the starting number to begin counting from: ";
    cin >> start;
    num_counter.set_counter(start);
    while(!input.eof())//while not the end of file
    {
        input >> next;
        if(next > 0)
            num_counter.increase_count();
        else
            num_counter.decrease_count();
    }
    cout << "\nThe counter is now: " << num_counter.return_count() << endl; function
    cout << "\nAfter adding 1 for every int. over 0, \nand subtracting 1 for all other int's read from the file, " << endl;
    num_counter.output_count(cout);
    cout << " is the new value of the counter!" << endl;

    return 0;
}

//default constructor for CounterType will set value of counter to zero
CounterType::CounterType()
{
    counter = 0;
}

//set counter member function sets value of counter to value of its argument if argument >= 0
void CounterType::set_counter(int value)
{
    if(value >= 0)
        counter = value;
    else
        counter = 0;
}

//increase member function increases counter by 1
void CounterType::increase_count()
{
    counter++;
}

//decrease member function decreases counter by 1 but does not allow counter to become negative
void CounterType::decrease_count()
{
    if(counter > 0)
        counter--;
}

//return member function returns the value of the private int counter
int CounterType::return_count()
{
    return counter;
}

//output member function outputs value of counter to the output stream specified in its argument
void CounterType::output_count(ostream& outs)
{
    outs << counter;
}


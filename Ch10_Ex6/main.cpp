/*
Justin Shores
CIS 201
Ch 10 Ex 6
this program will create a class named Month, it will have one member variable type int
it will use member functions to set value of month as int, set value of month as the first three letters of month
input month int value from stream, input three letters of month from stream,
output month int to stream, output month letters from stream, return value of member variable.
*my test program uses cin as input stream and cout as output stream,getting the months info from user
*/
#include <iostream>

using namespace std;

class Month
{
public:
     Month();
     void month_conversion(char, char, char);
     void month_conversion(int);
     void input_month(istream&);
     void input_int(istream&);
     void output_month(ostream&);
     void output_int(ostream&);
     int return_month();

private:
     int month;
};

//test program
int main()
{
    Month MonthTester;
    //prompt user
    cout << "Enter the first three letters of any month: ";
    MonthTester.input_month(cin);
    cout << "\nThe integer value of this month is: ";
    MonthTester.output_int(cout);
    cout << endl;
    //prompt user
    cout << "\nEnter the integer value of any month: ";
    MonthTester.input_int(cin);
    cout << "\nThe month for the integer value of " << MonthTester.return_month() << " is: ";
    MonthTester.output_month(cout);
    cout << endl;

    return 0;//end
}

//default member function
Month::Month()
{
    month = 0;
}

//member function gets info from user in letters form and call memeber function to convert to int
void Month::input_month(istream& ins)
{
    char one, two, three;
    ins >> one >> two >> three;
    month_conversion(one, two, three);
}

//member function gets int info from user and calls conversion member function
void Month::input_int(istream& ins)
{
    int value;
    ins >> value;
    month_conversion(value);
}

//member function takes letters of month and converts to int value of month
void Month::month_conversion(char one, char two, char three)
{
    switch(one)//switch statement to build cases for different months
    {
        case 'J': case 'j'://months starting with j
            switch(two)
            {
                case 'A': case 'a': month = 1;//january - 1
                break;
                case 'U': case 'u'://june or july
                    switch(three)
                    {
                        case 'N': case 'n': month = 6;//june - 6
                        break;
                        case 'L': case 'l': month = 7;//july - 7
                        break;
                    }
                break;
            }
            break;

        case 'F': case 'f'://february - 2
            month = 2;
            break;

        case 'M': case 'm'://march or may
            switch(two)
            {
                case 'A': case 'a':
                    switch(three)
                    {
                        case 'R': case 'r': month = 3;//march - 3
                        break;
                        case 'Y': case 'y': month = 5;//may - 5
                        break;
                    }
                    break;
            }
            break;

        case 'A': case 'a'://april or august
            switch(two)
            {
                case 'P': case 'p': month = 4;//april - 4
                break;
                case 'U': case 'u': month = 8;//august - 8
                break;
            }
            break;

        case 'S': case 's': month = 9;//septmeber - 9
        break;
        case 'O': case 'o': month = 10;//october - 10
        break;
        case 'N': case 'n': month = 11;//november - 11
        break;
        case 'D': case 'd': month = 12;//december - 12
        break;
    }
}

//member function assigns month value from users input
void Month::month_conversion(int month_value)
{
    month = month_value;//assign
}

//member function outputs letters to stream
void Month::output_month(ostream& outs)
{
    string months;//string to create month names
    switch(month)
    {
        case 1: months = "Jan.";break;//if month 1 months = jan
        case 2: months = "Feb.";break;//etc
        case 3: months = "Mar.";break;
        case 4: months = "Apr.";break;
        case 5: months = "May.";break;
        case 6: months = "Jun.";break;
        case 7: months = "Jul.";break;
        case 8: months = "Aug.";break;
        case 9: months = "Sep.";break;
        case 10: months = "Oct.";break;
        case 11: months = "Nov.";break;
        case 12: months = "Dec.";break;
    }
    outs << months;//out to stream
}

//member function to output int value to stream
void Month::output_int(ostream& outs)
{
    outs << month;//value of month output to stream
}

//member function to return the value of member variable
int Month::return_month()
{
    return month;//return member variable
}

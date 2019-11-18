#include<iostream>

using std::cout;
using std::cin;
using std::endl;

double getValue();
char getOperator();
void printResult(double a, char sm, double b);

int main()
{
    cout << "This app is a simple console calculator. " << endl;
    cout << "Follow the instructions. To complete the work - press 'Q'" << endl;
    char select;

    do
    {
        double a = getValue();
        char sm = getOperator();
        double b = getValue();

        printResult(a, sm, b);

        cout << "Continue? (Y - yes, Q-exit): ";
        cin >> select;
    }while(select != 'Q');
    cout << "The application is complete. All the best." << endl;
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
void printResult(double a, char sm, double b)
{
    if (sm == '+')
        cout << a << " + " << b << " is " << a + b << '\n';
    else if (sm == '-')
        cout << a << " - " << b << " is " << a - b << '\n';
    else if (sm == '*')
        cout << a << " * " << b << " is " << a * b << '\n';
    else if (sm == '/')
        cout << a << " / " << b << " is " << a / b << '\n';
    else
        cout << "Something went wrong: printResult() got an invalid operator.";

}
/////////////////////////////////////////////////////////////////////////////////////
char getOperator()
{
    while (true)
    {
        cout << "Enter one of the following: +, -, *, or /: ";
        char sm;
        cin >> sm;

        cin.ignore(32767,'\n');

        if (sm == '+' || sm == '-' || sm == '*' || sm == '/')
            return sm;
        else
            cout << "Oops, that input is invalid.  Please try again.\n";
        }
}
/////////////////////////////////////////////////////////////////////////////////////
double getValue()
{
    while (true)
    {
        cout << "Enter a double value: ";
        double a;
        cin >> a;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767,'\n');
            cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            cin.ignore(32767,'\n');
            return a;
        }
    }
}

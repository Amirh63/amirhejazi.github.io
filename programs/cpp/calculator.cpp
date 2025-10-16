// Amir Hejazi
// section # 4524
// A simple calculator
// Write an interactive program that performs as a very simple binary operations calculator.
// Your calculator should be able to handle the four basic math operations – add, subtract,
// multiply, and divide – on two input values. Your program should prompt the user to
// enter three arguments: two double values and a character to represent an operation.

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Function Prototype
double addition (double n, double m)    // Function heading
{
    return n + m;                       // Calculation
}

double subtraction (double n, double m) // Function heading
{
    return n - m;                       // Calculation
}

double multiplication (double n, double m) // Function heading
{
    return n * m;                       // Calculation
}

double division (double n, double m)    // Function heading
{
    return n / m;                       // Calculation
}
int main()
{
    system("COLOR 1e");
    // Declaring Variables
    char operation;
    double value1 = 0, value2 = 0, result = 0;

    // Input values
    cout << "Enter 2 numbers for the calculation process." << endl;
    cout << setprecision(2) << fixed;
    cout << "Enter number # 1:   \t";
    cin  >> value1;
    cout << "Enter number # 2:   \t";
    cin  >> value2;
    cin.ignore();
    cout << "Choose an operation: + - * /" <<endl;
    cin  >> operation;
    cout << endl;
    cout << "============================" << endl;

    // Calculation Process
    switch (operation)
    {
    case '+':  result = addition (value1,value2);
            cout << setw(13) <<value1 << endl;
            cout << operation << setw(12) << value2 << endl;
            cout << setw(13) <<"-------" << endl;
            cout << setw (13) <<result << endl;
            break;
    case '-':  result = subtraction (value1,value2);
            cout << setw(13) <<value1 << endl;
            cout << operation << setw(12) << value2 << endl;
            cout << setw(13) <<"-------" << endl;
            cout << setw (13) <<result << endl;
            break;
    case '*':  result = multiplication(value1,value2);
            cout << setw(13) <<value1 << endl;
            cout << operation << setw(12) << value2 << endl;
            cout << setw(13) <<"-------" << endl;
            cout << setw (13) <<result << endl;
            break;
    case '/':  result = division (value1,value2);
            cout << setw(13) <<value1 << endl;
            cout << operation << setw(12) << value2 << endl;
            cout << setw(13) <<"-------" << endl;
            cout << setw (13) <<result << endl;
            break;
    default:
        cout << "Invalid key...Run the program again and choose a valid key." << endl;
    }
    cout << "============================" << endl;
    //system("PAUSE");
    return 0;
}

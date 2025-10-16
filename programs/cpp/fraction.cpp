//Amir Hejazi
//Project#3B
#include <iostream>
#include <cstdlib>
using namespace std;
// Specification file for the fraction class
// This version has a constructor.
/*****************************************************************
*                           Class Specification                  *
*                           fraction declaration class           *
******************************************************************/
class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction();                                 //Constructor#1
    Fraction(int n,int d);                      //Constructor#2
    Fraction MultipliedBy (Fraction) const;     //Observer
    Fraction DividedBy(Fraction) const;         //Observer
    Fraction AddedTo(Fraction) const;           //Observer
    Fraction Subtract(Fraction) const;          //Observer
    bool isGreaterThan (Fraction) const;        //Observer
    bool isEqualTo (Fraction) const;            //Observer
    void print() const;                         //Observer

};

/*****************************************************************
*                           Client Code                          *
*                           Main Function                        *
******************************************************************/
int main()
{
    Fraction f1(9,8); //calling a parameterized class constructor
    Fraction f2(2,3); //calling a parameterized class constructor
    Fraction result;  //calling a default class constructor
    Fraction f3; //calling a default class constructor

    cout << "The result starts off at ";
    result.print(); //calling an observer function
    cout << endl;

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.MultipliedBy(f2); //a class binary operation - function
    result.print();
    cout << endl;

    //f3 = result; //assignment

    if (f2.isGreaterThan(f3)){ //a class relational expression - boolean operation/function
        f2.print();
        cout <<" is greater than ";
        f3.print();
        cout<<endl;
    } else {
        f2.print();
        cout <<" is less than ";
        f3.print();
        cout<<endl;
    }

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.AddedTo(f2); //a class binary operation - function
    result.print();
    cout << endl;


    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.Subtract(f2); //a class binary operation - function
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){ //a class relational expression - boolean operation/function
        cout << "The two fractions are equal." << endl;
    } else {
        cout << "The two fractions are not equal." << endl;
    }

    const Fraction f4(12, 8);
    const Fraction f5(202, 303);

    result = f4.DividedBy(f5); //a class binary operation - function
    cout << "The quotient of ";
    f4.print();
    cout << " and ";
    f5.print();
    cout << " is ";
    result.print();
    cout << endl;

    return 0;
}


/*****************************************************************
*                           Implementation                       *
******************************************************************/

//****************************************************************
// Overloading constructors initializes numerator and denominator*
//****************************************************************
//Constructor # 1
Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}
//Constructor # 2
Fraction::Fraction(int n,int d)
{
    numerator = n;
    denominator = d;
}
//*****************************************************************************
// Addition Function                                                          *
//*****************************************************************************
Fraction Fraction::AddedTo(Fraction Input) const
{
    Fraction output;
    int num1;
    int num2;

    num1                = Input.numerator * denominator;
    num2                = Input.denominator * numerator;
    output.numerator    = num1 + num2;
    output.denominator  = denominator * Input.denominator;

    return output;
}
//*****************************************************************************
// Subtraction Function                                                       *
//*****************************************************************************
Fraction Fraction::Subtract(Fraction Input) const
{
    Fraction output;
    int num1;
    int num2;

    num1                = Input.denominator * numerator;
    num2                = Input.numerator * denominator;
    output.numerator    = num1 - num2;
    output.denominator  = denominator * Input.denominator;

    return output;
}
//*****************************************************************************
// Multiplication Function                                                    *
//*****************************************************************************
Fraction Fraction::MultipliedBy(Fraction Input) const
{
    Fraction output;

    output.numerator    = numerator * Input.numerator;
    output.denominator  = denominator * Input.denominator;

    return output;
}
//*****************************************************************************
// division Function                                                          *
//*****************************************************************************
Fraction Fraction::DividedBy(Fraction Input) const
{
    Fraction output;

    output.numerator    = numerator * Input.denominator;
    output.denominator  = Input.numerator * denominator;

    return output;
}
//*******************************************************************************************************************
// boolean operation to compares two fraction objects to determine weather one object is greater than the other     *
//*******************************************************************************************************************
bool Fraction::isGreaterThan (Fraction input) const
{
    double frac1 = numerator/double (denominator);
    double frac2 = input.numerator/double (input.denominator);

    if( frac1 > frac2)
        return true;
    else
        return false;
}
//*******************************************************************************************************************
// boolean operation to compares two fraction objects to determine weather the fraction objects are equal           *
//*******************************************************************************************************************

bool Fraction::isEqualTo (Fraction input) const
{
    if (input.numerator == numerator && input.denominator == denominator)
        return true;
    else
        return false;
}
//*****************************************************************************
// Print shows the values of the member variable numerator and denominator.   *
//*****************************************************************************
void Fraction::print() const
{
    Fraction output;
    output.numerator = numerator;
    output.denominator = denominator;

    // determining the common factor
    int remainder;
    int divisor;
    int reduced;

    // determining the greatest common divisor
    if (output.numerator > output.denominator)
    {
        divisor = output.denominator;
        reduced = output.numerator;
    } else
    {
        divisor = output.numerator;
        reduced = output.denominator;
    }
    // deciphering the greatest common divisor
    while (divisor != 0)
    {
        remainder   = reduced % divisor;
        reduced     = divisor;
        divisor     = remainder;
    }
    // dividing the numerator and denominator by the greatest common divisor
    output.numerator = output.numerator/reduced;
    output.denominator = output.denominator/reduced;
    // print out the results
    if (output.numerator>0 && output.denominator >0)
        cout << output.numerator << "/" << output.denominator;
    else
        cout << -1*output.numerator <<"/" << abs(output.denominator);
}

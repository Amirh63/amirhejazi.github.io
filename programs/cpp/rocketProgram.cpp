// Project#1: Programming Challenge - Rocket program
// Amir Hejazi
// Section # 4524
#include <iostream>
using namespace std;

bool isEven(/*in*/int);                                     //function prototype
void drawCone(/*in*/int);                                   //function prototype
void drawEvenBox(/*in*/int, /*in*/int);                     //function prototype
void drawOddBox(/*in*/int, /*in*/int);                      //function prototype
void getDimension(/*out*/int&,/*out*/ int&, /*out*/int&);   //function prototype
void drawRocket(/*in*/int, /*in*/int, /*in*/int);           //function prototype

int main()
{
    // Declaring variables for the rocket shape
    int height = 0, width = 0, stages = 0, result = 0;
    char symbol;
    do
    {
    // getting the dimensions for the rocket
    getDimension(height,width,stages);
    // Drawing the rockets
    drawRocket(height, width, stages);
    //
    cout << "To run the program enter r/R or to quit enter q:" <<endl;
    cin  >> symbol;
    } while (symbol == 'r' || symbol == 'R');
    return 0;
}

//***************************************************************************************
//function definition                                                                   *
//using void function to draw the rockets                                               *
//pre-condition: values for parameter height, width, stages are passing to the function *
//***************************************************************************************
void drawRocket(/*in*/int height,/*in*/ int width,/*in*/ int stages)
{
     //functions for sample#1
    if (isEven(height))
    {
        drawCone(width);
        for (int counter=0; counter < stages; counter++)
        drawEvenBox(height,width);
        drawCone(width);
    } else {
    //functions for sample#2
        drawCone(width);
        for (int counter = 0; counter < stages; counter++)
        drawOddBox(height,width);
        drawCone(width);
    }

}

//******************************************************************************************************
//function definition                                                                                  *
//using void function to get the dimensions for the rocket                                             *
//Post-Condition: the values for parameters heightout, widthOut, stagesOut are passing to the function *
//******************************************************************************************************
void getDimension(/*out*/int& heightOut,/*out*/ int& widthOut,/*out*/ int& stagesOut)
{
    int heightIn = 0,
        widthIn  = 0,
        stagesIn = 0;
   // getting the users inputs
    cout << "Enter three values for the height, width, and stages of the rocket shape:"<< endl;
    cout << "The value for the height, width, and stages must be between 3 and 15." << endl;
    cout << "The height of each stage: " << endl;
    cin  >> heightIn;
    cout << "The width of each stage: " << endl;
    cin  >> widthIn;
    cout << "How many stages in the rocket: " << endl;
    cin  >> stagesIn;
    //Input validation
    while (!cin || (heightIn < 3 || heightIn > 15)
                || (widthIn  < 3 || widthIn  > 15)
                || (stagesIn < 3 || stagesIn > 15))
    {
        cin.clear();
        cin.ignore(10,'\n');
        cout << "The value for the height, width, and stages must be between 3 and 15." << endl;
        cout << "The height of each stage: " << endl;
        cin  >> heightIn;
        cout << "The width of each stage: " << endl;
        cin  >> widthIn;
        cout << "How many stages in the rocket: " << endl;
        cin  >> stagesIn;
    }
    heightOut = heightIn;
    widthOut  = widthIn;
    stagesOut = stagesIn;

}

//*********************************************************************
//function definition                                                 *
//using void function to display the cone for the rocket              *
//using the width of the rocket to determine the length of the cone   *
//Pre-condition: value for parameter width is passing to the function *
//*********************************************************************
void drawCone(/*in*/int width)
{
 // Declaring the variables for the while loop
    int row     = 1,
        counter = 0,
        space   = 2,
        column  = 0;

    //Determining the number of rows according to the width
    if (isEven(width))
    {
        column = width/2;
        while (row <= column)
        {
            int column2 = column;
            while (column2 > row)
            {
                column2 = column2 - 1;
                cout <<" ";
            }
            if (counter == 0)
                cout <<"*";
            cout << "*";
            // Displaying the line for the right side of the triangle
            if (counter > 0)
            {
                int column3 = 1;
                while(column3 <= space)
                {
                    cout <<" ";
                    column3 = column3 + 1;
                }
            cout << "*";
            space = space + 2;          // coutner for the space between shapes
            }
        counter++;                      // counter for the left side of the triangle
        row = row + 1;                  // counter for the rows of the triangle
        cout << endl;
        }
    }
    else
    {
        int space2 = 1;
        column = width/2+1;
        // Displaying the line for the left side of the triangle
        while (row <= column)
        {
            int column2 = column;
            while (column2 > row)
            {
                column2 = column2 - 1;
                cout <<" ";
            }
            cout << "*";
            // Displaying the line for the right side of the triangle
            if (counter > 0)
            {
                int column3 = 1;
                while(column3 <= space2)
                {
                    cout <<" ";
                    column3 = column3 + 1;
                }
            cout << "*";
            space2 = space2 + 2;          // coutner for the space between shapes
            }
        counter++;                      // counter for the left side of the triangle
        row = row + 1;                  // counter for the rows of the triangle
        cout << endl;
        }
    }
}
//***************************************************************************
// Definition of function isEven. This function accepts an                  *
// integer argument and tests it to be even or odd. The function            *
// returns true if the argument is even or false if the argument            *
// is odd. The return value is a bool.                                      *
// pre-condition: the value for number is passing to the function           *
// post-condition: the value for status is returning to the function call   *
//***************************************************************************
bool isEven(/*in*/ int number)
{
    bool status;

    if (number % 2 == 0)
        status = true;          //the number is even if there is no remainder
    else
        status = false;         //otherwise the number is odd
    return status;

}
//******************************************************************************************
//function definition                                                                      *
//using void function to display the hollow boxes for even number of rows                  *
//pre-condition: the values for parameters numRows, numColumns are passing to the function *
//******************************************************************************************
void drawEvenBox(/*in*/int numRows, /*in*/int numColumns)
{
    int rows = 1;

    while(rows <= numRows)
    {
        if (rows == 1 || rows == numRows)
        {
            //rows one and seven
            int columns = 1;
            while (columns <= numColumns)
            {
                cout << "*";
                columns++;
            }
        }
       // center rows
       else
        {
            cout << "*";
            int limits = 1;
            while (limits <= numColumns-2)
            {
                cout << " ";
                limits++;
            }
            cout << "*";
        }
        cout << endl;
        rows++;
    }
}
//***************************************************************************************
//function definition                                                                   *
//using void function to display the boxes for odd number of rows                       *
//pre-condition: the values for parameters rows and columns are passing to the function *
//***************************************************************************************
void drawOddBox(/*in*/int rows, /*in*/int columns)
{
    int colcount=1, rowcount=1;
    while(rowcount<=rows)
    {
    	colcount=1;
    	while(colcount<=columns)
    	{
        	cout<<"*";
        	colcount++;
    	}
    cout<<endl;
    rowcount++;
    }
}

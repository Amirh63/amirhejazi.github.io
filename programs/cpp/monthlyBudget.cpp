// Amir Hejazi
// Section # 4524
// Project # 3a

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

/*Hold data for student budget*/
struct MonthlyBudget
{
    // Data members
    float housing,
        utilities,
        houseHoldExp,
        transportation,
        food,
        medical,
        insurance,
        entertainment,
        clothing,
        miscellaneous;

    // Operation
    MonthlyBudget() // default constructor
    {
        housing=0;
        utilities=0;
        houseHoldExp=0;
        transportation=0;
        food=0;
        medical=0;
        insurance=0;
        entertainment=0;
        clothing=0;
        miscellaneous=0;
    }

    // parameterized constructor
    MonthlyBudget(float h,float u,float hHE, float t, float f,float m, float i, float e, float c, float ms)
    {
        housing=h;
        utilities=u;
        houseHoldExp=hHE;
        transportation=t;
        food=f;
        medical=m;
        insurance=i;
        entertainment=e;
        clothing=c;
        miscellaneous=ms;
    }

};
//Function Prototype to display the budget
void displayBudget(const MonthlyBudget&);
//Function Prototype to get the input values
void getExpenses(MonthlyBudget&);
// Function Prototype for comparing the functions
void compareExpenses(MonthlyBudget&,MonthlyBudget&);

int main()
{
    // calling the parameterized constructor to set the budget
    MonthlyBudget budget(500,150,65,50,230,30,100,150,75,50);
    displayBudget(budget);
    // Calling the parameterized constructor to get spending for the month
    MonthlyBudget spent;
    MonthlyBudget compared;
    // Calling the void function to get the input datas
    getExpenses(spent);
    displayBudget(spent);
    // comparing the monthly budget with the spent budget
    compareExpenses(budget,spent);

    return 0;
}

/********************************************************************
 * Displaying the items                                             *
 * This function displays the data stored in the members of an      *
 * MonthlyBudget structure variable passed to it as a constant      *
 * ******************************************************************/
void displayBudget(const MonthlyBudget &item)
{
    cout<<"Here is your monthly budget:\n"<<endl;
    cout<<"Housing"<<setw(10)<<"$"<<item.housing<<endl;
    cout<<"Utilities"<<setw(8)<<"$"<<item.utilities<<endl;
    cout<<"Household"<<setw(8)<<"$"<<item.houseHoldExp<<endl;
    cout<<"Transportation"<<setw(3)<<"$"<<item.transportation<<endl;
    cout<<"Food"<<setw(13)<<"$"<<item.food<<endl;
    cout<<"Medical"<<setw(10)<<"$"<<item.medical<<endl;
    cout<<"Insurance"<<setw(8)<<"$"<<item.insurance<<endl;
    cout<<"Entertainment"<<setw(4)<<"$"<<item.entertainment<<endl;
    cout<<"Clothing"<<setw(9)<<"$"<<item.clothing<<endl;
    cout<<"Miscellaneous"<<setw(4)<<"$"<<item.miscellaneous<<endl;
    cout <<endl<<endl;
}
/****************************************************************************
 *                          getExpenses                                     *
 * This function stores data input by the user in the members of an         *
 * MonthlyBudget structure variable passed to the function by reference.    *
 * **************************************************************************/
void getExpenses(MonthlyBudget &getInput)
{
    // getting data from user inputs
    cout <<"Enter actual monthly expenditures for each budget category \n"<<endl;
    cout <<"Rent/mortgage:" << setw(3) <<"$"; cin >> getInput.housing;
    cout <<"Utilities:" << setw(7) <<"$"; cin >> getInput.utilities;
    cout <<"Household:" << setw(7) <<"$"; cin >> getInput.houseHoldExp;
    cout <<"Transportation:" << setw(2) <<"$"; cin >> getInput.transportation;
    cout <<"Food:" << setw(12) <<"$"; cin >> getInput.food;
    cout <<"Medical:"<<setw(9)<<"$"; cin >> getInput.medical;
    cout <<"Insurance:"<<setw(7)<<"$"; cin >> getInput.insurance;
    cout <<"Entertainment:"<<setw(3)<<"$"; cin >> getInput.entertainment;
    cout <<"Clothing:"<<setw(8)<<"$"; cin >> getInput.clothing;
    cout <<"Miscellaneous:"<<setw(3)<<"$"; cin >> getInput.miscellaneous;
    cout <<endl<<endl;
    //Input validation
    while (!cin || getInput.housing<0        || getInput.utilities<0 || getInput.houseHoldExp<0
                || getInput.transportation<0 || getInput.food<0      || getInput.medical<0
                || getInput.insurance<0      || getInput.entertainment<0 || getInput.clothing<0
                || getInput.miscellaneous<0)
    {
    cin.clear();
    cin.ignore();
    cout << "Please do not enter a negative number for the monthly expenditures!"<<endl;
    cout <<"Enter actual monthly expenditures for each budget category \n"<<endl;
    cout <<"Rent/mortgage:" << setw(3) <<"$"; cin >> getInput.housing;
    cout <<"Utilities:" << setw(7) <<"$"; cin >> getInput.utilities;
    cout <<"Household:" << setw(7) <<"$"; cin >> getInput.houseHoldExp;
    cout <<"Transportation:" << setw(2) <<"$"; cin >> getInput.transportation;
    cout <<"Food:" << setw(12) <<"$"; cin >> getInput.food;
    cout <<"Medical:"<<setw(9)<<"$"; cin >> getInput.medical;
    cout <<"Insurance:"<<setw(7)<<"$"; cin >> getInput.insurance;
    cout <<"Entertainment:"<<setw(3)<<"$"; cin >> getInput.entertainment;
    cout <<"Clothing:"<<setw(8)<<"$"; cin >> getInput.clothing;
    cout <<"Miscellaneous:"<<setw(3)<<"$"; cin >> getInput.miscellaneous;
    cout <<endl<<endl;
    }
}
/****************************************************************************
 *                          Compare expenses                                *
 * This function compares input data by the user to the monthly budget and  *
 * Calculating the differences and the monthlybudget structure variable is  *
 * passed to the function by the reference.                                 *
 * **************************************************************************/
void compareExpenses(MonthlyBudget &budget,MonthlyBudget &spent)
{

    MonthlyBudget compare;
    // adjusting the output display
    cout << fixed<<showpoint<<setprecision(2);
    cout <<"\t\t" << "Budgeted     Spent      Difference" << endl;
    cout << "==================================================="<< endl;
    // calculating the expeneses for each month!
    compare.housing = budget.housing-spent.housing;
    cout << "Housing" <<"\t\t"<<budget.housing<<"\t     "<<spent.housing<<"\t"<<setw(5)<<compare.housing<<endl;
    compare.utilities = budget.utilities-spent.utilities;
    cout << "Utilities" <<"\t"<<budget.utilities<<"\t     "<<spent.utilities<<"\t"<<setw(5)<<compare.utilities<<endl;
    compare.houseHoldExp = budget.houseHoldExp-spent.houseHoldExp;
    cout << "Household" <<"\t"<<budget.houseHoldExp<<"\t     "<<spent.houseHoldExp<<"\t"<<setw(5)<<compare.houseHoldExp<<endl;
    compare.transportation = budget.transportation-spent.transportation;
    cout << "Transportation" <<"\t"<<budget.transportation<<"\t     "<<spent.transportation<<"\t"<<setw(5)<<compare.transportation<<endl;
    compare.food = budget.food-spent.food;
    cout << "Food" <<"\t\t"<<budget.food<<"\t     "<<spent.food<<"\t"<<setw(5)<<compare.food<<endl;
    compare.medical = budget.medical-spent.medical;
    cout << "Medical" <<"\t\t"<<budget.medical<<"\t     "<<spent.medical<<"\t"<<setw(5)<<compare.medical<<endl;
    compare.insurance = budget.insurance-spent.insurance;
    cout << "Isurance" <<"\t"<<budget.insurance<<"\t     "<<spent.insurance<<"\t"<<setw(5)<<compare.insurance<<endl;
    compare.entertainment = budget.entertainment-spent.entertainment;
    cout << "Entertainment" <<"\t"<<budget.entertainment<<"\t     "<<spent.entertainment<<"\t"<<setw(5)<<compare.entertainment<<endl;
    compare.clothing = budget.clothing-spent.clothing;
    cout << "Clothing" <<"\t"<<budget.clothing<<"\t     "<<spent.clothing<<"\t"<<setw(5)<<compare.clothing<<endl;
    compare.miscellaneous = budget.miscellaneous-spent.miscellaneous;
    cout << "Miscellaneous" <<"\t"<<budget.miscellaneous<<"\t     "<<spent.miscellaneous<<"\t"<<setw(5)<<compare.miscellaneous<<endl;
    cout <<"=================================================="<<endl;
    float budgetTotal =0;
    float spentTotal =0;
    float comparedTotal =0;
    // calculating the tolal for each category
    budgetTotal = budget.housing+budget.utilities+budget.houseHoldExp+budget.transportation+budget.food+budget.medical
                +budget.insurance+budget.entertainment+budget.clothing+budget.miscellaneous;
    spentTotal = spent.housing+spent.utilities+spent.houseHoldExp+spent.transportation
                +spent.food+spent.medical+spent.insurance+spent.entertainment+spent.clothing+spent.miscellaneous;
    comparedTotal = compare.housing+compare.utilities+compare.houseHoldExp+compare.transportation+compare.food
                + compare.medical+compare.insurance+compare.entertainment+compare.clothing+compare.miscellaneous;

     cout << "Total" <<"\t\t"<<budgetTotal<<"\t     "<<spentTotal<<"\t"<<setw(5)<<comparedTotal<<endl<<endl;
    //According to the results display the message
     if (comparedTotal > 0)
        cout << "Congratulation! You were $"<<comparedTotal<<" under budget this month."<<endl;
    else
        cout <<"Shame on you! You were $"<<abs(comparedTotal)<<" over budget this month."<<endl;

}


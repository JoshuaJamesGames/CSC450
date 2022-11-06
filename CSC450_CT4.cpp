/*
Program: 
Create a C++ program that will function as an Employee Salary Calculator.

Obtain from the user:
Double variables for 
Standard Hours worked
Rate of Pay
Overtime Hours (if applicable)

Calculate appropriate pay for standard hours and overtime (1.5 x rate of pay).
Provide formatted output using the following methods setw() setprecision()

Store the values into three different variables. 
For each double variable, create a double pointer to dynamic memory. 
Display the contents of the variables and pointers.  
In your program, be sure to use the new operator and delete operators to 
manage dynamic memory.
*/

#include <iostream>
#include <iomanip>
#include <limits.h>

using namespace std;

//Input validation function for positive double with limit
void inputDouble(double *ptr_input, double limit)
{
   //Input loop
   while(true){
      
       cin >> *ptr_input;
       //If the input can be assigned, break out of loop
       if(cin.good() && (*ptr_input >= 0) && (*ptr_input <= limit)){
           break;
       //Otherwise, output feedback and clear input buffer
       }else{
           cout << "Incorrect Input!" << endl;
           cout << "Please enter a Positive Number: ";
           cin.clear();
           cin.ignore(INT_MAX,'\n');
       }
   }
}

int main(int argc, char const *argv[])
{
    //Variable Double pointers with initialization
    double *ptr_standardHoursWorked = new double();
    double *ptr_overtimeHoursWorked = new double();
    double *ptr_rateOfPay = new double();

    //Limits for range validation
    //24*7*365
    const double MAX_HOURS = 61320.0;
    //Sqrt(DOUB_MAX_VALUE)
    const double MAX_PAY = 1.34078e+154;

    if(!ptr_standardHoursWorked || !ptr_overtimeHoursWorked || !ptr_rateOfPay){
       cout << "Memory allocation failed!" << endl;
       return 0;
   }
    //Intro
    cout << "Welcome to the Employee Salary Calculator Program!" << endl;
    cout << "Let's collect some information" << endl;

    //Prompt for 3 Values with inputDouble
    cout << "\nHow many standard hours were worked? ";
    inputDouble(ptr_standardHoursWorked, MAX_HOURS);

    cout << "\nHow many overtime hours were worked? ";
    inputDouble(ptr_overtimeHoursWorked, MAX_HOURS);

    cout<< "\nWhat is the rate of pay? ";
    inputDouble(ptr_rateOfPay, MAX_PAY);

    //Calculate and modify overTimeHours value
    *ptr_overtimeHoursWorked *= 1.5;

    //Output created columns using setw and 2 decimal places using setprecision
    cout << "\nThe pay calculations are as follows:";

    //Standard hours
    cout << "\nStandard Hours worked: " << fixed << setprecision(2);
    cout << setw(10) << *ptr_standardHoursWorked << " @" << (*ptr_rateOfPay); 
    cout << " earning $" << *ptr_standardHoursWorked * (*ptr_rateOfPay);

    //Overtime hours
    cout << "\nOvertime Hours worked: ";
    cout << setw(10) << *ptr_overtimeHoursWorked << " @" << *ptr_rateOfPay * 1.5;
    cout << " earning $" << *ptr_overtimeHoursWorked * 1.5 * (*ptr_rateOfPay);
    
    //Total hours
    cout << "\nTotal Hours worked: " << setw(13) << *ptr_standardHoursWorked + *ptr_overtimeHoursWorked << " hours";
    cout<< "\nTotal Earnings: " << setw(13) << "$" << (*ptr_standardHoursWorked + (*ptr_overtimeHoursWorked * 1.5)) * (*ptr_rateOfPay);

    //Free Memory
    delete ptr_standardHoursWorked;
    delete ptr_overtimeHoursWorked;
    delete ptr_rateOfPay;

    //Outtro
    cout<< "\nGoodbye!";


    return 0;
}

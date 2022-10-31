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

//Input validation function for double only
void inputDouble(double *ptr_input)
{
   //Input loop
   while(true){
      
       cin >> *ptr_input;
       //If the input can be assigned, break out of loop
       if(cin.good()){
           break;
       //Otherwise, output feedback and clear input buffer
       }else{
           cout << "Incorrect Input!" << endl;
           cout << "Please enter an Number: ";
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

    if(!ptr_standardHoursWorked || !ptr_overtimeHoursWorked || !ptr_rateOfPay){
       cout << "Memory allocation failed!" << endl;
       return 0;
   }
    //Intro
    cout << "Welcome to the Employee Salary Calculator Program!" << endl;
    cout << "Let's collect some information" << endl;

    //Prompt for 3 Values with inputDouble
    cout << "How many standard hours were worked? " << '\n';
    inputDouble(ptr_standardHoursWorked);

    cout << "How many overtime hours were worked? " << '\n';
    inputDouble(ptr_overtimeHoursWorked);

    cout<< "What is the rate of pay? " << '\n';
    inputDouble(ptr_rateOfPay);

    //Calculate and modify overTimeHours value
    *ptr_overtimeHoursWorked *= 1.5;

    //Output
    cout << "The pay calculations are as follows: \n";
    cout << "Standard Hours worked: " << fixed << setprecision(2);
    cout << setw(10) << *ptr_standardHoursWorked << '\n';
    cout << "Overtime Hours worked: ";
    cout << setw(10) << *ptr_overtimeHoursWorked << '\n';
    cout << "Total Hours worked: " << *ptr_standardHoursWorked + *ptr_overtimeHoursWorked << '\n';

    //Free Memory
    delete ptr_standardHoursWorked;
    delete ptr_overtimeHoursWorked;
    delete ptr_rateOfPay;

    //Outtro
    cout<< "\nGoodbye!";


    return 0;
}

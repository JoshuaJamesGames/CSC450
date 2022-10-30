#include <iostream>
#include <limits.h>
using namespace std;

//Input validation function for integers only
void inputNum(int *ptr_input)
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
           cout << "Please enter an Integer: ";
           cin.clear();
           cin.ignore(INT_MAX,'\n');
       }
   }
}

int main(int argc, char const *argv[])
{
  
   //Create 3 int pointers, to assign collected value addresses   
   int *ptr_input1 = new (nothrow) int;     
   int *ptr_input2 = new (nothrow) int;   
   int *ptr_input3 = new (nothrow) int;

   //Check for correct memory allocation
   if(!ptr_input1 || !ptr_input2 || !ptr_input3){
       cout << "Memory allocation failed!" << endl;
       return 0;
   }
         
   //Introduction & Directions
   cout << "Welcome to the Integer Pointer Program!" << endl;
   cout << "Let's collect 3 integers" << endl;
  
   //Prompt for 3 integer values using inputNum
   cout << endl << "What is Integer #1: ";   
   inputNum(ptr_input1);   

   cout << endl << "What is Integer #2: ";
   inputNum(ptr_input2);   

   cout << endl << "What is Integer #3: ";
   inputNum(ptr_input3);   
  
   //Output collected integer values and addresses
   cout << endl << "The collected integers are: " << endl;
   cout << "Integer # 1 is : " << *ptr_input1 << " at address " << ptr_input1 << endl;
   cout << "Integer # 2 is : " << *ptr_input2 << " at address " << ptr_input2 << endl;
   cout << "Integer # 3 is : " << *ptr_input3 << " at address " << ptr_input3 << endl << endl;
     
   //Releasing the memory allocated for the pointers    
   delete ptr_input1;
   delete ptr_input2;
   delete ptr_input3;

   //Outtro
   cout << endl << "Goodbye!";   
   return 0;
}

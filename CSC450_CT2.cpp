#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // Variables
    int NumOfStrings = 3;
    string buffer;

    //Introduction & Directions
    cout << "Welcome to the String Reverser!" << endl;
    cout << "Let's reverse " << NumOfStrings << " strings" << endl;
    
    //Loop NumOfStrings times, prompt for string
    for(int i = 1; i<=NumOfStrings; i++){

        cout << endl << "What is String #" << i << ": ";
        getline(cin, buffer);

        cout << "String " << i << " reversed is: ";
        //Reverse string using for loop and index
        for(int j = buffer.length(); j >= 0; j--){
            cout << buffer[j];
        }  
        cout << endl;
    };

    //Outtro
    cout << endl << "Goodbye!";    
    return 0;
}

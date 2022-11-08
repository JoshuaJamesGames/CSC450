/*
Program: Create a C++ program that will obtain input from a user and store it 
into the provided CSC450_CT5_mod5.txt 

Your program should append it to the provided text file, without deleting 
the existing data:

Store the provided data in the CSC450_CT5_mod5.txt file.

Create a reversal method that will reverse all of the characters in the 
CSC450_CT5_mod5.txt file and store the result in a 
CSC450-mod5-reverse.txt file.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

//Input validation function for file
void fileInput(string fileName)
{
   //Input loop
   while(true){
      
        string buffer;
        fstream outputFile;

        outputFile.open(fileName, ios::out | ios::app);
        cout << "What would you like to add to " << fileName << "?" << endl;

        getline(cin, buffer);

        if(cin.good()){
            outputFile << endl << buffer;
            cout << "\nYour comments have been added" << endl;
            break;
        //Otherwise, output feedback and clear input buffer
        }else{
            cout << "\nIncorrect Input!" << endl;
            cout << "Please enter a valid String: ";            
        }
        outputFile.close();
   }
}

void reverseText(string inputFileName, string outputFileName)
{
    string buffer;
    ifstream inputFile;
    ofstream outputFile;

    inputFile.open(inputFileName, ios::in);
    outputFile.open(outputFileName, ios::out);

    cout << "\nCreated " << outputFileName << " concatenating reversed text" << endl;

    while(getline(inputFile, buffer)){
        reverse(buffer.begin(), buffer.end());
        outputFile << buffer << endl;
    }

    inputFile.close();
    outputFile.close();

}

int main(int argc, char const *argv[])
{
    const string requiredFile = "CSC450_CT5.mod5.txt";
    const string reverseOutputFile = "CSC450-mod5-reverse.txt";
    
    //Intro
    cout << "Welcome to the User Input Program" << endl;
    cout << "Opening " << requiredFile << endl;

    //User input
    fileInput(requiredFile);

    //Reverse requiredFile into reverseOutputFile
    reverseText(requiredFile, reverseOutputFile);

    //Outtro
    cout << "\nGoodbye!";

    return 0;
}

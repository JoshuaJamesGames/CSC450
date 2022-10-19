#include <iostream>;
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int NumOfStrings = 3;
    string buffer;

    cout << "Welcome to the String Reverser!" << endl;
    cout << "Let's reverse " << NumOfStrings << " strings" << endl;
    
    for(int i = 1; i<=NumOfStrings; i++){
        cout << "What is String #" << i << ": ";
        getline(cin, buffer);

        cout << "String " << i << " reversed is: ";
        for(int j = buffer.length(); j >= 0; j--){
            cout << buffer[j];
        }  
        cout << endl;
    };

    cout << endl << "Goodbye!";    
    return 0;
}

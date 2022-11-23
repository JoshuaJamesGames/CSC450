#include <iostream>
#include <thread>
using namespace std;

void countUp(int &i){

    while(i<100){
        cout<< i << " ";
        i++;
    }
    //Output final digit outside of loop
    cout<< i;
    cout<< "\nDone counting up!" << endl;

}

void countDown(int &i){
    while(i>0){
        cout<< i << " ";
        i--;
    }
    //Output final digit outside of loop
    cout<< i;
    cout<< "\nDone counting down!" << endl;
}

int main(int argc, char const *argv[])
{
    //Initialize variable
    int i = 100;

    //Call first thread and pass i by reference
    thread t1(countDown, ref(i));
    //Wait until t1 finishes
    t1.join();

    //Call second thread and pass i by reference
    thread t2(countUp, ref(i));
    //Wait until t2 finishes
    t2.join();

    return 0;
}

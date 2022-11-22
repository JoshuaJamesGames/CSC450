#include <iostream>
#include <thread>
using namespace std;

void countUp(int &i){

    while(i<=100){
        cout<< i << " ";
        i++;
    }
    cout<< "\nDone counting up!" << endl;

}

void countDown(int &i){
    while(i>=0){
        cout<< i << " ";
        i--;
    }
    cout<< "\nDone counting down!" << endl;
}

int main(int argc, char const *argv[])
{
    int i = 0;

    thread t1(countUp, ref(i));
    t1.join();

    thread t2(countDown, ref(i));
    t2.join();

    return 0;
}

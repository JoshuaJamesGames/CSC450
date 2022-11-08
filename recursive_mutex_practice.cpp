#include <mutex>
#include <iostream>

struct Complex {
    std::recursive_mutex mutex;
    int i;

    Complex() : i(5) {}

    void mul(int x){
        std::lock_guard<std::recursive_mutex> lock(mutex);
        i *= x;
        std::cout << i << std::endl;
    }

    void div(int x){
        std::lock_guard<std::recursive_mutex> lock(mutex);
        i /= x;
        std::cout << i << std::endl;
    }

    void both(int x, int y){
    std::lock_guard<std::recursive_mutex> lock(mutex);
    mul(x);
    div(y);
    std::cout << i << std::endl;
}
};

int main(){
    Complex complex;
    complex.mul(4);
    complex.div(2);
    complex.both(32, 23);

    return 0;
}
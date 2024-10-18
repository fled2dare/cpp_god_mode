#include <iostream>

int *dangling_pointer(){
    int temp = new int(10);
    return &temp;
}

int main(){
    int *ptr = new int(10);
    delete ptr;
    std::cout << ptr << std::endl;

    // dangling using a function
    int *f = dangling_pointer();
    std::cout << f << std::endl;
}
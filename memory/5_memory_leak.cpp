// This code leaks memory.
// Fix it by releasing allocated memory properly.

#include <iostream>

void doSomething() {
    int* data = new int[100];
    data[0] = 42;

    std::cout << "First value: " << data[0] << std::endl;

    // FIX: `data` is never deallocated.
    // Since `data` is used only within this function we can 
    // IRL, for this use case where `data` is used only within this function, it's better just to use stack `int data[100]`.
    delete[] data;
}

int main() {
    doSomething();
    return 0;
}
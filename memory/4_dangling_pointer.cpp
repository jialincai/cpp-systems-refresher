// This code has a dangling pointer bug.
// Fix it so `ptr` always points to valid memory.

#include <iostream>

using namespace std;

int* createValue() {
    // BUG HERE: returns address of local variable
    // `local` is on the stack, which is deallocated after this function returns.
    // int local = 123;
    // return &local;

    int* local = new int(123);
    return local;
}

int main() {
    int* ptr = createValue();

    cout << "Value: " << *ptr << endl;
    delete ptr;

    return 0;
}
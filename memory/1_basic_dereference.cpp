// Create an int variable with value 42.
// Create a pointer to it, then print the value using the pointer.

#include <iostream>

using namespace std;

int main() {
    int x = 42;
    int* ptr = &x;

    cout << "Value via pointer: " << *ptr << endl;

    return 0;
}
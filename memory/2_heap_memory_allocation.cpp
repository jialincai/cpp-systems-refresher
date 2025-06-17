// Allocate an `int` on the heap using `new`.
// Assign it the value 99, print it, then deallocate.

#include <iostream>

using namespace std;

int main() {
    int* heap_int = new int(99);
    cout << "Value allocated on heap: " << *heap_int << endl;

    delete heap_int;
    cout << "Value after deallocation: " << *heap_int << endl;

    return 0;
}
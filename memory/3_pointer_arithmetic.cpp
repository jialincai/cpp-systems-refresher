// Allocate an array of 5 integers on the heap.
// Use pointer arithmetic to assign values 10, 20, 30, 40, 50.
// Print them using pointer arithmetic (not array indexing)

#include <iostream>

using namespace std;

int main() {
    int* arr = new int[5];

    for (int i = 0; i < 5; i++) {
        *(arr + i) = (i + 1) * 10;
    }

    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << *(arr + i) << endl;
    }

    delete[] arr;

    return 0;
}
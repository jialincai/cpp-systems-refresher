// Create a new thread that prints "Hello from thread!".
// Wait for the thread to complete before main exits.

#include <iostream>
#include <thread>

using namespace std;

void greet() {
    cout << "Hello from thread!" << endl;
}

int main() {
    thread t(greet);
    t.join(); // Important: wait for thread to finish
    return 0;
}
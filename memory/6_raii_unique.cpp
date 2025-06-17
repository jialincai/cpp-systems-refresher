// Use `std::unique_ptr` to manage memory for a single integer.
// Set its value to 77, print it, no need to call delete.
#include <iostream>
#include <memory>

using namespace std;

int main() {
    unique_ptr<int> u_ptr = make_unique<int>(77);
    cout << "Unique value: " << *u_ptr << endl;

    return 0;
}
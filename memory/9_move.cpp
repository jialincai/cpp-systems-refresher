// Move the contents of one string into another using `std::move`.
// Then print both strings and observe what happens.
#include <iostream>

using namespace std;

int main() {
    string s1("Hi, how are you?");
    string s2("Good and you?");

    cout << "String 1 before move: " << s1 << endl;
    cout << "String 2 before move: " << s2 << endl;

    s2 = move(s1);

    cout << "String 1 after move: " << s1 << endl;
    cout << "String 2 after move: " << s2 << endl;

    return 0;
}
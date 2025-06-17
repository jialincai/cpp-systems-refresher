// Use `std::shared_ptr` to share ownership of an int across two scopes.
// Print out the number of reference to the shared pointer in both scopes.
#include <iostream>
#include <memory>

using namespace std;

void print_shared(shared_ptr<int> ptr) {
    cout << "Shared pointer: " << *ptr << endl;
    cout << "Use counter during function: " << ptr.use_count() << endl;
}

int main() {
    shared_ptr<int> s_ptr = make_shared<int>(555);
    print_shared(s_ptr);

    cout << "Use counter after function: " << s_ptr.use_count() << endl;

    return 0;
}
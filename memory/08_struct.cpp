// Define a `struct Person { std::string name; }`
// Allocate a Person on the heap using unique_ptr
// Print their name
#include <iostream>
#include <memory>

using namespace std;

struct Person {
    string name;
};

int main()  {
    unique_ptr<Person> u_ptr = make_unique<Person>("Jane Doe");
    cout << "Person's name: " << u_ptr->name << endl;
}
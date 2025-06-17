// Spawn 3 threads:
// - Each thread should print: "Thread X: Hello from thread!"
// - X is the thread's ID passed in as an argument
// - Each thread should increment a shared counter (by reference)

// The shared counter should output three.
// The thread output may be garbled? Why?

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

void thread_fn(int X, int& counter, mutex& mtx) {
    cout << "Thread " << X << ": Hello from thread!" << endl; // std::cout is a shared global stream.
                                                              // The individual << operations are separate function calls
                                                              // so without a lock this output is garbled.
    
    lock_guard<mutex> u_lock(mtx);
    counter++;
}

int main() {
    vector<thread> t_group;
    int counter = 0;
    mutex mtx;

    for (int i = 0; i < 3; i++) {
        t_group.emplace_back(thread_fn, i + 1, ref(counter), ref(mtx));
    }

    for (auto& t : t_group) {
        t.join();
    }

    cout << "Final shared counter: " << counter << endl;
    
    return 0;
}
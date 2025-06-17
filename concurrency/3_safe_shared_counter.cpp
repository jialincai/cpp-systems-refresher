// Same as Exercise 2, but now use `std::mutex` to ensure correct output.

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

int counter = 0; // You can also use atomic<int> counter(0) for this simple example.
mutex mtx;

void increment_1000() {
    for (int i = 0; i < 1000; i++) {
        lock_guard<mutex> lock(mtx); // This lock ensures that only one thread can execute this block at a time.
        /*
         * If you want RAII aligned manual control or condition variable compatibility, use:
         * unique_lock<mutex> u_lock(mtx, defer_lock);
         * u_lock.lock();
         * u_lock.unlock();
         */
        counter++;
        this_thread::yield();
    }
}

int main() {
    vector<thread> t_group;
    for (int i = 0; i < 10; i++) {
        t_group.emplace_back(increment_1000);
    }

    for (thread& t : t_group) {
        t.join();
    }

    cout << "Expected counter value: " << 10000 << endl;
    cout << "Actual counter value  : " << counter << endl;

    return 0;
}
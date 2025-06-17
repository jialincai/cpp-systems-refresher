// Spawn 10 threads. Each increments a shared variable `counter` 1000 times.
// No mutex used. Observe the race condition.

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int counter = 0;

void increment() {
    for (int i = 0; i < 1000; ++i) {
        ++counter;
        this_thread::yield(); // Yield to allow other threads to run
                              // Note: Increases the probabily of race conditions for this example
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

    /*
     * This program is not thread-safe, because multiple threads are reading from and writing to a
     * shared variable counterconcurrently without any synchronization (e.g., no mutex or atomic operations).
     * As a result, the expected behavior is non-deterministic. Sometimes the final output might be
     * 10000, but often it will be less than that due to race conditions. The actual result depends
     * on how the threads are scheduled by the OS.
     * The reason we typically see a value less than 10000 is because the statement counter++ is 
     * not atomic — it consists of three steps:
     *    1. Read the value of counter into a temporary register.
     *    2. Increment the value in the register.
     *    3. Write the incremented value back to counter.
     * If two threads perform these steps at the same time, it's possible they both read the same
     * initial value, increment it independently, and both write it back — effectively losing one increment.
     * So when this happens repeatedly across many threads, the final count ends up being less than expected.
     */

    return 0;
}
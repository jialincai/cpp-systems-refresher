// This code simulates a deadlock.
// What causes the deadlock and how can we fix it WITHOUT REMOVING any locks.

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m1, m2;

void task1() {
    // lock_guard<mutex> lock1(m1, adopt_lock);
    // this_thread::sleep_for(chrono::milliseconds(100));
    // lock_guard<mutex> lock2(m2, adopt_lock);
    // cout << "Task 1 done\n";


    // You could also use scoped_lock lock(m1, m2); to lock both mutexes atomically using RAII
    lock(m1, m2); // Manually lock both mutexes — MUST be followed by adopt_lock to avoid double locking and enforce RAII.
    lock_guard<mutex> lock1(m1, adopt_lock); // RAII begins — take ownership without locking again
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> lock2(m2, adopt_lock); // Same as above.
    cout << "Task 1 done\n";
}

void task2() {
    // lock_guard<mutex> lock2(m2, adopt_lock);
    // this_thread::sleep_for(chrono::milliseconds(100));
    // lock_guard<mutex> lock1(m1, adopt_lock);
    // cout << "Task 2 done\n";

    lock(m1, m2);
    lock_guard<mutex> lock1(m1, adopt_lock);
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> lock2(m2, adopt_lock);
    cout << "Task 2 done\n";
}

int main() {
    thread t1(task1);
    thread t2(task2);

    t1.join();
    t2.join();

    return 0;
}
/**
 * Deadlock occurs because task1 and task2 acquire mutexes in different orders (m1→m2 vs m2→m1).
 * If both threads acquire their first lock and then try to acquire the second, they can block each other indefinitely.
 *
 * Fix: Use lock(m1, m2) to atomically acquire both mutexes in a consistent order,
 *      then wrap them in lock_guard using adopt_lock to avoid double-locking.
 */

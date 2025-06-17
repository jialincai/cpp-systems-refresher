// Use `std::condition_variable` to alternate between printing "Ping" and "Pong"
// Print: Ping Pong Ping Pong... for 10 times

#include <condition_variable>
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;
condition_variable cv;
bool ping_turn = true;

void print_ping() {
    for (int i = 0; i < 10; i++) {
        unique_lock<mutex> u_lock(mtx); // Acquire lock via RAII.
        cv.wait(u_lock, [] { return ping_turn; }); // Release `u_lock` if condition not met.
                                                   // Thread sleeps until awakened by `notify_one`.
                                                   // If condition is met, attain lock and continue.
        cout << "Ping ";
        ping_turn = false;
        cv.notify_one(); // Notify sleeping threads to check condition.
    }
    
}

void print_pong() {
    for (int i = 0; i < 10; i++) {
        unique_lock<mutex> u_lock(mtx);
        cv.wait(u_lock, [] { return !ping_turn; });
        cout << "Pong ";
        ping_turn = true;
        cv.notify_one();
    }
}

int main() {
    thread ping_thread(print_ping);
    thread pong_thread(print_pong);

    ping_thread.join();
    pong_thread.join();
    
    return 0;
}
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using std::cout;
using std::endl;


std::mutex mtx;

void print(char ch) {
    std::unique_lock<std::mutex> ul(mtx, std::defer_lock);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    ul.lock();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            cout << ch;
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
        cout << endl;
    }
    cout << endl;
    ul.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main() {

    std::thread th1(print, '^');
    std::thread th2(print, ':');

    th1.join();
    th2.join();
}
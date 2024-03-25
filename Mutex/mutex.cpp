#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using std::cout;
using std::endl;

std::mutex mtx;

void print(char ch) {
    
    
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    // mtx.lock();
    {
        std::lock_guard<std::mutex> guard(mtx);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++)
            {
                cout << ch;
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
            }
            cout << endl;
        }
        cout << endl;
        // mtx.unlock();
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main() {
    cout << "Mutex!" << endl;
    std::thread th1(print, '*');
    std::thread th2(print, '#');
    std::thread th3(print, '@');

    th1.join();
    th2.join();
    th3.join();
}
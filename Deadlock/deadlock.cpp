#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using std::cout;
using std::endl;

std::mutex mtx1;
std::mutex mtx2;

void print() {
    mtx2.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    mtx1.lock();
    {
        // std::lock_guard<std::mutex> guard(mtx);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++)
            {
                cout << '*';
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
            }
            cout << endl;
        }
        cout << endl;
        
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    mtx1.unlock();
    mtx2.unlock();
}

void print2() {
    mtx2.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    mtx1.lock();
    {
        // std::lock_guard<std::mutex> guard(mtx);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++)
            {
                cout << '#';
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
            }
            cout << endl;
        }
        cout << endl;
        
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    mtx1.unlock();
    mtx2.unlock();
}

int main() {
    cout << "Mutex!" << endl;
    std::thread th1(print);
    std::thread th2(print2);
    std::thread th3(print);

    th1.join();
    th2.join();
    th3.join();
}
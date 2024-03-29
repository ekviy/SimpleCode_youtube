#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using std::cout;
using std::endl;


std::recursive_mutex rm;

void foo(int a) {
    rm.lock();
    cout << a << " ";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    if (a <= 1) {
        cout << endl;
        rm.unlock();
        return;
    }

    a--;
    foo(a);
    rm.unlock();
};

int main() {

    cout << "Recourseve mutex!" << endl;

    // rm.lock();
    // rm.lock();
    std::thread th1(foo, 10);
    std::thread th2(foo, 10);
    // foo(10);

    th1.join();
    th2.join();
    // rm.unlock();
    // rm.unlock();
}
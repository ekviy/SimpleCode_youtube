#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;

class MyClass{
public:
    void doWork() {

        std::this_thread::sleep_for(std::chrono::milliseconds(2'000));

        cout << "========\t" << "DoWork STARTED\t========" << endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(5'000));

        cout << "ID thread = " << std::this_thread::get_id() << "====DoWork STOPPED\t========" << endl;
    }
    void doWork2(int a) {

        std::this_thread::sleep_for(std::chrono::milliseconds(2'000));

        cout << "========\t" << "DoWork2 STARTED\t========" << endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(5'000));

        cout << "doWork2() a = " << a << endl;

        cout << "ID thread = " << std::this_thread::get_id() << "====DoWork2 STOPPED\t========" << endl;
    }

    int sum(int a, int b) {

        std::this_thread::sleep_for(std::chrono::milliseconds(2'000));

        cout << "========\t" << "SUM STARTED\t========" << endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(5'000));

        cout << "ID thread = " << std::this_thread::get_id() << "====sum STOPPED\t========" << endl;

        return a + b;
    }
};

int main() {

    cout << "Multithread!" << endl;

    MyClass m;
    
    std::thread th(&MyClass::doWork2, m, 5);



    for (size_t i = 0; i < 10; i++) {
        cout << "ID thread = " << std::this_thread::get_id()
            << "\tMAIN works"  << "\t" << i << endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    th.join();
}
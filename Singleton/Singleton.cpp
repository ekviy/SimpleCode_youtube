#include <iostream>
#include <mutex>
#include <thread>


using std::cout;
using std::endl;

class Singleton {
private:
    Singleton() {};
    Singleton(const Singleton& s);
    Singleton operator=(const Singleton& s);
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
};

int main() {
    std::mutex mutex;
    std::lock_guard {mutex};
    cout << "Singleton realisation!" << endl;
    [[maybe_unused]] Singleton& s = Singleton::getInstance();
}
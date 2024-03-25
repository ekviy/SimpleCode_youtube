#include <iostream>
#include <functional>
#include <vector>

using std::cout;
using std::endl;

void foo(int a) {
    if ( a > 10 && a < 40) {
        cout << "FOO " << a << endl;
    }
}

void bar(int a) {
    if ( a % 2 == 0) {
        cout << "BAR " << a << endl;
    }
}

void baz(int a) {
    cout << "BAZ " << a << endl;
}

int sum(int a, int b) {
    return a + b; 
}

void doWork(std::vector<int>& v,
    std::vector< std::function<void(int)> > funcVector) {
    for (auto el : v) {
        for (auto& func : funcVector) {
            func(el);
        }
    }
}

void doWork(std::vector<int>& v, std::function<void(int)> func) {
    for (auto el : v) {
        func(el);
    }
}

int main() {
    cout << "std::function !" << endl;

    std::vector<int> v = { 1, 51, 4, 10, 44, 98, 12, 22, 49 };

    // std::vector< std::function<void(int)> > funcV = {foo, bar, baz};
    // doWork(v, funcV);

    // lambda func []() {}
    int p = 0;

    auto f = [&p]() {
        p = 5;
    };

    f();

    // doWork(v, [](int a) {
    //     cout << "lamba function is called with a = " << a << endl;
    // });
}
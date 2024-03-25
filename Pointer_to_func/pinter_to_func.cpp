#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::string;


// func type (* pointer name)(parameters list)

int foo1(int a) {
    return a - 1;
}

int foo2(int a) {
    return a * 2;
}

string getDataFromDb(string resourse) {
    return "Data from " + resourse;
}

string getDataFromWeb(string resourse) {
    return "Data from Web " + resourse;
}

void showInfo(string(*func)(string r), string r) {
    cout << func(r) << endl;
}

int main() {
    cout << "std::function. Lambda" << endl;
    int (*fooPointer)(int a);

    fooPointer = foo1;
    cout << fooPointer(13) << endl;

    fooPointer = foo2;
    cout << fooPointer(44) << endl;

    // string (*funcPointer)() = dataFromDb;
    showInfo(getDataFromDb, "astral");
}
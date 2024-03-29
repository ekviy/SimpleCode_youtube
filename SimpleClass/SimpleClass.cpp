#include <iostream>

using std::cout;
using std::endl;

class Person final {
private:
    int data;
public:
    Person(int value) {
        data = value;
        cout << "Constructor is called. " << this << endl;
    }
    Person(const Person& rhs) {
        this->data = rhs.data;
        cout << "COPY Constructor is called. " << this << endl;
    }

    Person& operator=(const Person& other){
        cout << "operator = is called " << this << endl;
        this->data = other.data;
        return *this;
    }

    bool operator==(const Person& other){
        cout << "operator = is called " << this << endl;
        return this->data == other.data;
    }

    ~Person() {
        cout << "Destructor is called. " << this << endl;
    }
};

class Point final{
private:
    int x;
    int y;

public:
    Point(int a, int b) {
        x = a;
        y = b;
    }
    bool operator==(const Point& other){
        return (this->x == other.x && this->y == other.y);
    }
    bool operator!=(const Point& other){
        return !(this->x == other.x && this->y == other.y);
    }

    void print() {
        cout << "X = " << this->x << endl;
        cout << "Y = " << this->y << endl;
    }

    friend void changeParams(Point& value);
};

void changeParams(Point& value) {
    value.x = 42;
    value.y = 42;
}

class Apple final {
    
}

int main() {
    cout << "Simple Class!";

    Point p1(5,1);
    Point p2(5,1);

    bool isEqual = (p1 == p2);
    bool isNotEqual = (p1 != p2);

    cout << "p1 is equal p2? " << isEqual << endl;
    cout << "p1 is NOT equal p2? " << bool(isNotEqual) << endl;
    p1.print();
    changeParams(p1);
    p1.print();
}
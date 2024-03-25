#include <iostream>
#include <string>

template <typename T>
class SmartPointer {
public:
    SmartPointer(T* rhs) {
        this->ptr = rhs;
        std::cout << "SmartPointer constr\n";
    }

    ~SmartPointer() {
        delete ptr;
        ptr = nullptr;
        std::cout << "SmartPointer destr\n";
    }

    T& operator*() {
        return *ptr;
    }

    T* getPtr() {
        return this->ptr;
    }

private:
    T* ptr;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, SmartPointer<T>& obj) {
    return os << obj.getPtr();
}


int main() {

    std::cout << "Dynamic memory" << std::endl;
    
    int* pa = new int(10);
    std::cout << "pa: " << pa << std::endl;
    std::cout << "*pa: " << *pa << std::endl;

    pa = nullptr;
    std::cout << "pa: " << pa << std::endl;
    delete pa;

    SmartPointer<int> sptr = new int(5);
    std::cout << "SmartPointer: " << sptr << std::endl;
    std::cout << "SmartPointer value: " << *sptr << std::endl;

    *sptr = 999;
    std::cout << "SmartPointer value: " << *sptr << std::endl;


    SmartPointer<std::string> string_sp1 = new std::string("string_sp1");
    std::cout << "String1 SmartPointer: " << *string_sp1 << std::endl;
    SmartPointer<std::string> string_sp2 = new std::string("string_sp2");
    std::cout << "String2 SmartPointer: " << *string_sp2 << std::endl;

    // string_sp2 = string_sp1;
    std::cout << "String2 SmartPointer after =sp1: " << *string_sp2 << std::endl;

    // delete *string_sp1;
    // std::cout << "String2 SmartPointer after delete sp1: " << *string_sp2 << std::endl;
    
}

#include <vector>
#include <iostream>

int main() {
    std::cout << "Vector!" << std::endl;

    std::vector<int> v(10, 10);

    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }

    std::cout << "v size: " << v.size() << std::endl;
    std::cout << "v capacity: " << v.capacity() << std::endl;

    v.push_back(1);

    std::cout << "v size: " << v.size() << std::endl;
    std::cout << "v capacity: " << v.capacity() << std::endl;

    v.reserve(111);

    std::cout << "v size: " << v.size() << std::endl;
    std::cout << "v capacity: " << v.capacity() << std::endl;

    v.shrink_to_fit();

    std::cout << "v size: " << v.size() << std::endl;
    std::cout << "v capacity: " << v.capacity() << std::endl;

    v.resize(33, 9);

    std::cout << "v size: " << v.size() << std::endl;
    std::cout << "v capacity: " << v.capacity() << std::endl;
}
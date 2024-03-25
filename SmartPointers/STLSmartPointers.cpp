#include <iostream>
#include <memory>
#include <cstdlib>

using namespace std;

int main() {
    cout << "STL Smart Pointers" << endl;

    // auto_ptr<int> ap1(new int(5));

    // auto_ptr<int> ap2(ap1);

    std::unique_ptr<int> uptr1(new int(5));
    std::unique_ptr<int> uptr2(std::move(uptr1));
    std::unique_ptr<int> uptr3;

    uptr3.swap(uptr2);

    // int* usual_ptr = uptr3.get();

    // cout << "usual_ptr: " << usual_ptr << endl;

    // delete usual_ptr; // will delete variable in unique_ptr as well

    uptr3.release();

    std::shared_ptr<int> shared_ptr1(new int(7));
    std::shared_ptr<int> shared_ptr2(shared_ptr1);

    *shared_ptr2 = 121;
    int SIZE = 5;
    // cin >> SIZE;
    int* arr = new int[SIZE] {1, -4, 87, 143, 0};

    std::shared_ptr<int[]> shared_arr(arr);

    for (int i = 0; i < SIZE; i++) {
        shared_arr[i] = rand() % 15;
        cout << shared_arr[i] << " ";
    }

    shared_arr = nullptr;
}
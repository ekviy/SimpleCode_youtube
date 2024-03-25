#include <iostream>
#include <vector>

int main() {
    using namespace std;
    std::cout << "Iterators!" << std::endl;

    int arr[] = {7, -33, 987};
    cout << arr[2] << endl;
    cout << *(arr + 2) << endl;

    std::vector<int> v = {-6, 9, 8, 80, 0, 65};
    cout << v[3] << endl;

    vector<int>::iterator it = v.begin();
    cout << it[3] << endl;
    cout << *(it + 1) << endl;
    cout << *(it) << endl;
    it = it + 3; 
    cout << *(it) << endl;
    // cout << it.at(3) << endl;

    std::vector<int>::const_iterator it_const = v.begin();
    cout << "*it_const = " << *it_const << endl;

    for (std::vector<int>::reverse_iterator it_cout = v.rbegin(); it_cout < v.rend(); it_cout++) {
        cout << *it_cout << " ";
    }

    vector<int>::iterator it_adv = v.begin();
    cout << "\nit_adv = " << *(it_adv + 2) << endl;
    advance(it_adv, 3);
    cout << "\nit_adv = " << *(it_adv) << endl;

    vector<int>::iterator it_insert = v.begin();
    cout << "insert\n";
    v.insert(it_insert, 999);

    for (std::vector<int>::const_iterator it_cout = v.cbegin(); it_cout < v.cend(); it_cout++) {
        cout << *it_cout << " ";
    }

    vector<int>::iterator it_erase = v.begin() + 3;
    v.erase(it_erase, it_erase + 3);

    cout << "erase\n";

    for (std::vector<int>::const_iterator it_cout = v.cbegin(); it_cout < v.cend(); it_cout++) {
        cout << *it_cout << " ";
    }
}
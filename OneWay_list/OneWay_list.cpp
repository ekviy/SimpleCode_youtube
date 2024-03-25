#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

template <typename T>
class List final {
public:
    List();
    ~List();

    void push_back(T data);
    int getSize() const {return size;};

    T& operator[](const int index);

    void pop_front();
    void clear();

    void push_front(T data);
    void insertAt(T data, int index);
    void removeAt(int index);
    void pop_back();

private:

    class Node final{
    public:
        Node* pNext_;
        T data_;
        Node(T data = T(), Node* pNext = nullptr){
            data_ = data;
            pNext_ = pNext;
        }
    };

    Node* head;
    int size;
};

template <typename T>
List<T>::List() {
    size = 0;
    head = nullptr;
}

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
void List<T>::pop_back() {
    this->removeAt(getSize() - 1);
}

template <typename T>
void List<T>::insertAt(T data, int index) {
    if (index == 0) {
        push_front(data);
    } else {
        Node* previous = this->head;
        for (int i = 1; i < index; i++) {
            previous = previous->pNext_;
        }
        Node* newElem = new Node(data, previous->pNext_);
        previous->pNext_ = newElem;

        size++;
    }
}

template <typename T>
void List<T>::removeAt(int index) {
    if (index == 0) {
        pop_front();
    } else {
        Node* previous = this->head;
        for (int i = 1; i < index; i++) {
            previous = previous->pNext_;
        }
        Node* toDelete = previous->pNext_;
        previous->pNext_ = toDelete->pNext_;
        delete toDelete;

        size--;
    }
}

template <typename T>
void List<T>::push_front(T data) {
    Node* newElem = new Node(data, this->head);
    head = newElem;
    size++;
}

template <typename T>
void List<T>::clear() {
    while (size) {
        this->pop_front();
    }
}

template <typename T>
void List<T>::pop_front() {
    Node* temp = head;
    head = head->pNext_;
    delete temp;
    size--;
}

template <typename T>
void List<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node(data);
    } else {
         Node* current = this->head;
         while (current->pNext_ != nullptr) {
            current = current->pNext_;
         }
         current->pNext_ = new Node(data);
    }
    this->size ++;
}

template <typename T>
T& List<T>::operator[](const int index) {
    Node* current = head;
    int counter = 0;
    while (current != nullptr) {
        if (counter == index) {
            return current->data_;
        }
        current = current->pNext_;
        counter++;
    }

    throw std::out_of_range("Index is out of range of this list");
}

int main() {
    cout << "OneWay List!" << endl;

    List<int> lst;
    lst.push_back(5);
    lst.push_back(20);
    lst.push_back(22);

    cout << lst.getSize() << endl;
    cout << lst[1] << endl;

    for (int i = 0; i < lst.getSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;

    lst.pop_front();
    for (int i = 0; i < lst.getSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;

    lst.clear();
    lst.push_back(99);
    for (int i = 0; i < lst.getSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;

    lst.push_front(27);
    for (int i = 0; i < lst.getSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;

    lst.insertAt(28, 1);
    for (int i = 0; i < lst.getSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;

    lst.removeAt(1);
    for (int i = 0; i < lst.getSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;

    lst.pop_back();
    cout << "pop_back" << endl;
    for (int i = 0; i < lst.getSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;
}
#include <iostream>
#include <limits>
using namespace std;

class DynamicArray {
    int *buffer;
    int size_;
    int capacity_;

    void ensure_capacity(int newCapacity) {
        if (newCapacity < 1) newCapacity = 1;
        int *newBuffer = new int[newCapacity];
        for (int i = 0; i < size_; ++i) newBuffer[i] = buffer[i];
        delete[] buffer;
        buffer = newBuffer;
        capacity_ = newCapacity;
    }

public:
    DynamicArray() : buffer(nullptr), size_(0), capacity_(0) {}
    ~DynamicArray() { delete[] buffer; }

    void append(int value) {
        if (size_ == capacity_) {
            int newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            ensure_capacity(newCapacity);
        }
        buffer[size_++] = value;
    }

    bool insert_at(int index, int value) {
        if (index < 0 || index > size_) return false;
        if (size_ == capacity_) {
            int newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            ensure_capacity(newCapacity);
        }
        for (int i = size_; i > index; --i) buffer[i] = buffer[i - 1];
        buffer[index] = value;
        ++size_;
        return true;
    }

    bool remove_at(int index) {
        if (index < 0 || index >= size_) return false;
        for (int i = index; i + 1 < size_; ++i) buffer[i] = buffer[i + 1];
        --size_;
        if (size_ == 0) {
            delete[] buffer;
            buffer = nullptr;
            capacity_ = 0;
        } else if (size_ < capacity_ / 4) {
            int newCapacity = capacity_ / 2;
            if (newCapacity < 1) newCapacity = 1;
            ensure_capacity(newCapacity);
        }
        return true;
    }

    void display() const {
        if (size_ == 0) {
            cout << "Array is empty\n";
            return;
        }
        cout << "Array contents (" << size_ << "): ";
        for (int i = 0; i < size_; ++i) {
            cout << buffer[i];
            if (i + 1 < size_) cout << " ";
        }
        cout << "\n";
    }

    int size() const { return size_; }
};

int main() {
    DynamicArray arr;
    while (true) {
        cout << "\nChoose an operation:\n"
             << "1. Insert at end\n"
             << "2. Delete at position\n"
             << "3. Display\n"
             << "4. Exit\n"
             << "Enter choice: ";
        int choice;
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }

        if (choice == 1) {
            cout << "Enter integer to insert: ";
            int value;
            if (cin >> value) {
                arr.append(value);
                cout << "Inserted " << value << ".\n";
            } else {
                cout << "Invalid value.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else if (choice == 2) {
            if (arr.size() == 0) {
                cout << "Array is empty. Nothing to delete.\n";
                continue;
            }
            cout << "Enter position (0-based) to delete: ";
            int index;
            if (cin >> index) {
                if (arr.remove_at(index)) cout << "Deleted element at position " << index << ".\n";
                else cout << "Invalid position.\n";
            } else {
                cout << "Invalid input.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else if (choice == 3) {
            arr.display();
        } else if (choice == 4) {
            cout << "Exiting.\n";
            break;
        } else {
            cout << "Unknown choice.\n";
        }
    }
    return 0;
}
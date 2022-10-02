#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class LinkedList {
private:
    Node *first;
public:
    LinkedList() {
        first = nullptr;
    }

    LinkedList(const int *A, int n) {
        if (A == nullptr || n == 0) {
            return;
        }
        Node *last, *temp;
        first = new Node;
        first->data = A[0];
        first->next = nullptr;
        last = first;
        for (int i = 1; i < n; ++i) {
            temp = new Node;
            temp->data = A[i];
            temp->next = nullptr;
            last->next = temp;
            last = temp;
        }
        temp = nullptr;
        last = nullptr;
        delete temp;
        delete last;
    }

    ~LinkedList() {
        Node *p = first;
        while (p != nullptr) {
            first = p;
            p = p->next;
            delete first;
        }
        delete p;
    }

    void display() {
        if (first == nullptr)
            return;
        Node *temp = first;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        delete temp;
    }

    int length() {
        if (first == nullptr)
            return 0;
        Node *temp = first;
        int count = 0;
        while (temp != nullptr) {
            ++count;
            temp = temp->next;
        }
        delete temp;
        return count;
    }

    void insert(int index, int x) {
        if (index < 0 || index > length())
            return;

        Node *temp = new Node;
        temp->data = x;
        temp->next = nullptr;
        if (index == 0) {
            temp->next = first;
            first = temp;
        } else {
            Node *current = first;
            for (int i = 0; i < (index - 1); ++i) {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
            current = nullptr;
            delete current;
        }
        temp = nullptr;
        delete temp;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

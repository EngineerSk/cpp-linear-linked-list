#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = nullptr;

void create(const int A[], int n) {
    int i;
    Node *temp, *last;
    first = (struct Node *) malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (i = 1; i < n; ++i) {
        temp = (struct Node *) malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}

int count(const struct Node *p) {
    if (p == nullptr)
        return 0;
    int counter = 0;
    while (p != nullptr) {
        ++counter;
        p = p->next;
    }
    return counter;
}

int deleteElement(struct Node *p, int index) {
    if (index < 1 || index > count(p))
        return -1;
    int x;
    if (p == nullptr)
        return -1;
    else {
        if (index == 1) {
            first = p->next;
            x = p->data;
            delete p;
            return x;
        }
        struct Node *q = p;
        for (int i = 1; i <= (index - 1) && p != nullptr; ++i) {
            q = p;
            p = p->next;
        }
        if (p != nullptr) {
            x = p->data;
            q->next = p->next;
            delete p;
            return x;
        }
    }
    return -1;
}

void removeDuplicate(struct Node *p) {
    if (p == nullptr || p->next == nullptr)
        return;
    struct Node *q = p->next;
    while (q != nullptr) {
        if (p->data == q->data) {
            struct Node *temp = q;
            p->next = q->next;
            q = q->next;
            delete temp;
        } else {
            p = q;
            q = p->next;
        }

    }

}

void display(const struct Node *p) {
    while (p != nullptr) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {
    int A[] = {3, 5, 7, 7, 10, 11, 13, 13, 15, 15, 18, 20, 20, 20, 21};
    create(A, sizeof(A) / sizeof(int));
    display(first);
    cout << endl;
    cout << "Element " << deleteElement(first, 0) << " is deleted" << endl;
    display(first);
    cout << endl;
    removeDuplicate(first);
    display(first);
    return 0;
}
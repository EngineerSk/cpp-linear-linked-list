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

void display(const struct Node *p) {
    while (p != nullptr) {
        printf("%d ", p->data);
        p = p->next;
    }
}

struct Node *linearSearch(struct Node *p, int key) {
    while (p != nullptr) {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return p;
}

struct Node *recursiveLinearSearch(struct Node *p, int key) {
    if (p == nullptr)
        return p;
    if (p->data == key)
        return p;
    return recursiveLinearSearch(p->next, key);
}

struct Node *headNodeLinearSearch(struct Node *p, int key) {
    if (p == nullptr)
        return p;
    struct Node *q = nullptr;
    while (p != nullptr) {
        if (p->data == key) {
            if (q != nullptr) {
                q->next = p->next;
                p->next = first;
                first = p;
            }
            return p;
        }
        q = p;
        p = p->next;
    }
    return nullptr;
}

struct Node *recursiveHeadNodeLinearSearch(struct Node *p, struct Node* q, int key) {
    if (p == nullptr)
        return p;
    if (p->data == key) {
        if (q != nullptr) {
            q->next = p->next;
            p->next = first;
            first = p;
        }
        return p;
    }
    return recursiveHeadNodeLinearSearch(p->next, p, key);
}

int main() {
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 15};
    create(A, sizeof(A) / sizeof(int));
    display(first);
    cout << endl;
    temp = recursiveLinearSearch(first, 7);
    if (temp != nullptr)
        cout << "Recursive Linear search: " << temp << endl;
    else
        cout << "Key is not found!" << endl;
    temp = linearSearch(first, 17);
    if (temp != nullptr)
        cout << "Linear search address: " << temp << endl;
    else
        cout << "Key is not found!" << endl;
    temp = recursiveHeadNodeLinearSearch(first, nullptr, 7);
    if (temp != nullptr)
        cout << "Head node Linear search address: " << temp << endl;
    else
        cout << "Key is not found!" << endl;
    display(first);
    return 0;
}

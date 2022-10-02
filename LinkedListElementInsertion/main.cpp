#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = nullptr, *lastNode = nullptr;

void create(const int *A, int n) {
    if (A == nullptr)
        return;
    struct Node *temp, *last;
    first = (struct Node *) malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = nullptr;
    last = first;
    for (int i = 1; i < n && (&A[i] != nullptr); ++i) {
        temp = (struct Node *) malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}

int count(struct Node *p) {
    if (p == nullptr)
        return 0;
    int counter = 0;
    while (p != nullptr) {
        ++counter;
        p = p->next;
    }
    return counter;
}

void insert(struct Node *p, int index, int x) {
    if (index < 0 || index > count(p))
        return;
    auto *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = nullptr;
    if (index == 0) {
        temp->next = first;
        first = temp;
        return;
    }
    for (int i = 0; i < (index - 1); ++i) {
        p = p->next;
    }
    if (p != nullptr) {
        temp->next = p->next;
        p->next = temp;
    }
}

struct Node *sortedListElementInsertion(struct Node *p, int x) {
    struct Node *q = nullptr, *t;
    t = (struct Node *) malloc(sizeof(struct Node));
    t->data = x;
    t->next = nullptr;
    if (p == nullptr) {
        t->next = first;
        first = t;
    }

    while (p != nullptr) {
        if (q != nullptr) {
            if (x <= p->data) {
                q->next = t;
                t->next = p;
                break;
            }
        } else {
            if (x <= p->data) {
                t->next = p;
                first = t;
                break;
            }
        }
        q = p;
        p = p->next;
        if (p == nullptr) {
            q->next = t;
        }
    }
    return first;
}

void insertAtLast(struct Node *p, int x) {
    auto *t = (struct Node *) malloc(sizeof(struct Node));
    t->data = x;
    t->next = nullptr;
    if (first == nullptr) {
        t->next = first;
        first = t;
        lastNode = first;
        return;
    }
    while (p->next != nullptr && lastNode == nullptr) {
        p = p->next;
    }
    if (lastNode == nullptr) {
        lastNode = p;
    }
    t->next = lastNode->next;
    lastNode->next = t;
    lastNode = t;
}

void display(struct Node *p) {
    if (p == nullptr)
        return;
    while (p != nullptr) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {
    int A[] = {3, 5, 7, 10, 15};
    create(A, sizeof(A) / sizeof(int));

//    insert(first, 5, 10);
    sortedListElementInsertion(first, 0);
    sortedListElementInsertion(first, 17);
    sortedListElementInsertion(first, 35);

    cout << "Linked list has " << count(first) << " nodes" << endl;
    display(first);
    sortedListElementInsertion(first, 35);
    cout << endl;
    cout << "Linked list has " << count(first) << " nodes" << endl;
    display(first);
    return 0;
}

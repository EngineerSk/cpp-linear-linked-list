#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = nullptr;

void display(struct Node *p);

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
    if (&(p->data) == nullptr)
        return 0;
    int counter = 0;
    while (p != nullptr) {
        ++counter;
        p = p->next;
    }
    return counter;
}

void reverseLinkedListUsingPointerToArray(struct Node *p) {
    struct Node *q = p;
    int *A, i = 0;
    int size = count(p);
    if (size == 0)
        return;
    A = (int *) malloc(sizeof(int) * size);
    for (; i < size; ++i) {
        A[i] = q->data;
        q = q->next;
    }
    while (i > 0) {
        p->data = A[--i];
        p = p->next;
    }
}

struct Node *reverseLinkedListUsingSlidingPointers(struct Node *p) {
    if (p == nullptr)
        return p;

    struct Node *previous = nullptr;

    while (p != nullptr) {
        struct Node *current = p->next;
        p->next = previous;
        previous = p;
        p = current;
    }
    return previous;
}

struct Node *recursiveReversedLinkedListUsingSlidingPointers(struct Node *pNode, struct Node *previous) {
    if (pNode == nullptr)
        return previous;
    if (pNode->next != nullptr) {
        struct Node *temp = pNode->next;
        pNode->next = previous;
        return recursiveReversedLinkedListUsingSlidingPointers(temp, pNode);
    }
    pNode->next = previous;
    return pNode;
}

void display(struct Node *p) {
    while (p != nullptr) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {
    int A[] = {3, 5, 7, 7, 10, 11, 11, 11, 12, 13, 15, 15, 17, 20, 20, 21};
    create(A, sizeof(A) / sizeof(A[0]));
    display(first);
    reverseLinkedListUsingPointerToArray(first);
    cout << endl;
    display(first);
    cout << endl;
    first = reverseLinkedListUsingSlidingPointers(first);
    display(first);
    cout << endl;
    first = recursiveReversedLinkedListUsingSlidingPointers(first, nullptr);
    display(first);
    return 0;
}

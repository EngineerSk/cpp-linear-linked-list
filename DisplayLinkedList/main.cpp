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

void recursiveDisplay(const struct Node *p) {
    if (p != nullptr) {
        printf("%d ", p->data);
        recursiveDisplay(p->next);
    }
}

int main() {
    cout << "Hello, World!" << endl;
    int A[] = {3, 5, 7, 10, 15};
    create(A, sizeof(A) / sizeof(int));
    display(first);
    cout << endl;
    recursiveDisplay(first);
    return 0;
}

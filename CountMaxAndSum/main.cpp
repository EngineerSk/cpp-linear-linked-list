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

int count(const struct Node *p) {
    int nodeCount = 0;
    while (p != nullptr) {
        ++nodeCount;
        p = p->next;
    }
    return nodeCount;
}

int recursiveCount(const struct Node *p) {
    if (p != nullptr)
        return recursiveCount(p->next) + 1;
    return 0;
}

int sum(const struct Node *p) {
    int nodeElementsSum = 0;
    while (p != nullptr) {
        nodeElementsSum += p->data;
        p = p->next;
    }
    return nodeElementsSum;
}

int recursiveSum(const struct Node *p) {
    if (p == nullptr)
        return 0;
    return recursiveSum(p->next) + p->data;
}

int max(const struct Node *p) {
    int nodeMax = INT32_MIN;
    while (p != nullptr) {
        if (p->data > nodeMax)
            nodeMax = p->data;
        p = p->next;
    }
    return nodeMax;
}

int recursiveMax(const struct Node *p) {
    int nodeMax = INT32_MIN;
    if (p == nullptr)
        return nodeMax;
    nodeMax = recursiveMax(p->next);
    if (p->data < nodeMax)
        return nodeMax;
    return p->data;
}

const struct Node *min(const struct Node *p) {
    int nodeMin = INT32_MAX;
    const struct Node *nodeMinAddress = nullptr;
    if (p == nullptr)
        return nullptr;
    while (p != nullptr) {
        if (p->data < nodeMin) {
            nodeMin = p->data;
            nodeMinAddress = p;
        }
        p = p->next;
    }
    return nodeMinAddress;
}

const struct Node *recursiveMin(const struct Node *p) {
    const struct Node *nodeMinPtr = nullptr;
    if (p == nullptr)
        return nodeMinPtr;
    nodeMinPtr = p;
    if (p->next != nullptr)
        nodeMinPtr = recursiveMin(p->next);
    if (nodeMinPtr->data < p->data)
        return nodeMinPtr;
    return p;
}

int main() {
    int A[] = {3, 65, 7, 10, 64};
    create(A, sizeof(A) / sizeof(int));
    display(first);
    cout << endl;
    recursiveDisplay(first);
    printf("\nLength is %d", recursiveCount(first));
    printf("\nSum is %d", recursiveSum(first));
    printf("\nMax is %d", recursiveMax(first));
    cout << endl;
    cout << recursiveMin(first)->data << endl;
    return 0;
}

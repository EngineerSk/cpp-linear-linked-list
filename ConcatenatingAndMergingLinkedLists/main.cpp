#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node *create(const int *A, int n) {
    if (A == nullptr)
        return nullptr;
    struct Node *start, *end;
    start = (struct Node *) malloc(sizeof(struct Node));
    start->data = A[0];
    start->next = nullptr;
    end = start;
    for (int i = 1; i < n; ++i) {
        auto *temp = (struct Node *) malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = nullptr;
        end->next = temp;
        end = temp;
    }
    return start;
}

int count(struct Node *pNode) {
    if (pNode == nullptr)
        return 0;
    int counter = 0;
    while (pNode != nullptr) {
        ++counter;
        pNode = pNode->next;
    }
    return counter;
}

void display(struct Node *pNode) {
    if (pNode == nullptr)
        return;
    while (pNode != nullptr) {
        printf("%d ", pNode->data);
        pNode = pNode->next;
    }
}

struct Node *concat(struct Node *pNode, struct Node *qNode) {
    if (pNode != nullptr) {
        struct Node *tempNode = pNode, *last;
        while (tempNode != nullptr) {
            if (tempNode->next == nullptr)
                last = tempNode;
            tempNode = tempNode->next;
        }
        if (qNode != nullptr)
            last->next = qNode;
        return pNode;
    }
    return qNode;
}

struct Node *merge(struct Node *pNode, struct Node *qNode) {
    if (pNode == nullptr) {
        if (qNode != nullptr)
            return qNode;
        return pNode;
    }
    struct Node *start, *end;
    if (pNode->data < qNode->data) {
        start = pNode;
        pNode = pNode->next;

    } else {
        start = qNode;
        qNode = qNode->next;
    }
    start->next = nullptr;
    end = start;

    while (pNode != nullptr && qNode != nullptr) {
        Node *temp;
        if (pNode->data < qNode->data) {
            temp = pNode;
            pNode = pNode->next;
        } else {
            temp = qNode;
            qNode = qNode->next;
        }
        temp->next = nullptr;
        end->next = temp;
        end = temp;
    }
    if (pNode != nullptr)
        end->next = pNode;
    if (qNode != nullptr)
        end->next = qNode;
    return start;
}

struct Node *reverse(struct Node *pNode) {
    if (pNode == nullptr)
        return pNode;
    if (pNode->next == nullptr)
        return pNode;
    struct Node *previous = nullptr;
    while (pNode != nullptr) {
        struct Node *temp = pNode->next;
        pNode->next = previous;
        previous = pNode;
        pNode = temp;
    }
    return previous;
}

bool isLoop(struct Node *pNode) {
    if (pNode == nullptr)
        return false;
    if (pNode->next == nullptr)
        return false;
    struct Node *firstPointer, *secondPointer;
    firstPointer = secondPointer = pNode;
    while (firstPointer != nullptr && secondPointer != nullptr && firstPointer != secondPointer) {
        firstPointer = firstPointer->next;
        secondPointer = secondPointer->next;
        if (secondPointer != nullptr)
            secondPointer = secondPointer->next;
    }
    if (firstPointer == secondPointer)
        return true;
    return false;
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    int B[] = {3, 5, 7, 10, 15, 18, 20, 21};
    struct Node *first = create(A, sizeof(A) / sizeof(int)), *second = create(B, sizeof(B) / sizeof(int));
    display(first);
    cout << endl;
    display(second);
    cout << endl;
    struct Node *mergeLinks = merge(first, second);
    mergeLinks = reverse(mergeLinks);
    display(mergeLinks);
    cout << endl;
    mergeLinks = reverse(mergeLinks);
    display(mergeLinks);
    cout << endl;
    display(reverse(mergeLinks));
    cout << endl;
    return 0;
}

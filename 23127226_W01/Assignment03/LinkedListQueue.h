#ifndef _LINKEDLISTQUEUE_H_
#define _LINKEDLISTQUEUE_H_
struct Node {
    int data;
    Node* pNext;
};

struct LinkedListQueue {
    // attributes
    Node *head, *tail;
    int capacity; // max number of elements
    int num; // current number of elements
    // functions
    void init(int);
    void enqueue(int);
    int dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
    void clear();
};
#endif


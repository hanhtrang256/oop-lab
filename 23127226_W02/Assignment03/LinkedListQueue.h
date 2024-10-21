#ifndef _LINKEDLISTQUEUE_H_
#define _LINKEDLISTQUEUE_H_
#include "Node.h"

class LinkedListQueue {
private:
    // attributes
    Node *head, *tail;
    int capacity; // max number of elements
    int num; // current number of elements
public:
    // functions
    void init(int);
    int getCapacity();
    void enqueue(int);
    int dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
    void clear();
};
#endif


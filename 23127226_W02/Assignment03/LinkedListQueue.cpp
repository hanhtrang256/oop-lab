#include "LinkedListQueue.h"
#include <iostream>

using namespace std;

const int INVALID_CONST = -999999;

int LinkedListQueue::getCapacity() {
    return capacity;
}

void LinkedListQueue::init(int inputCapacity) {
    head = nullptr;
    tail = nullptr;
    capacity = inputCapacity;
    num = 0;
}

bool LinkedListQueue::isEmpty() {
    return num == 0;
}

bool LinkedListQueue::isFull() {
    return num == capacity;
}

void LinkedListQueue::enqueue(int x) {
    if (capacity == 0 || num == capacity) {
        std::cout << "Cannot push element to this queue!\n";
        return;
    }
    Node* newNode = new Node(x);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
        ++num;
        // cout << newNode->data << '\n';
        return;
    }
    tail->setNext(newNode);
    tail = newNode;
    ++num;
}

int LinkedListQueue::dequeue() {
    if (isEmpty()) {
        // queue is being empty
        std::cout << "Queue is currently empty!\n";
        return INVALID_CONST;
    }

    // if queue only has 1 element
    if (num == 1) {
        int save = head->getData();
        delete head;
        head = nullptr;
        tail = nullptr;
        num = 0;
        return save;
    }

    // more than 1 element
    int saveData = head->getData();
    Node* saveHead = head;
    head = head->getNext();
    delete saveHead;
    --num;
    return saveData;
}

int LinkedListQueue::peek() {
    if (isEmpty()) {
        std::cout << "Queue is currently empty!\n";
        return INVALID_CONST;
    }
    return head->getData();
}

void LinkedListQueue::clear() {
    if (isEmpty()) {
        std::cout << "Queue is currently empty!\n";
        return;
    }

    int saveData;
    while (!isEmpty()) 
        saveData = dequeue();
}
#include "Node.h"

Node::Node() {
    data = 0;
    pNext = nullptr;
}

Node::Node(int x) {
    data = x;
    pNext = nullptr;
}

int Node::getData() {
    return data;
}

Node* Node::getNext() {
    return pNext;
}

void Node::setNext(Node* other) {
    pNext = other;
}


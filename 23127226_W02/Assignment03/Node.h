#ifndef _NODE_H_
#define _NODE_H_

class Node {
private:
    int data;
    Node* pNext;
public: 
    Node();
    Node(int);
    int getData();
    Node* getNext();
    void setNext(Node* other);
};

#endif 
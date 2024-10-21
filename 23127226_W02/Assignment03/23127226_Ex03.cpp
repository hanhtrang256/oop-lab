#include <iostream>
#include <vector>
#include <string>
#include "LinkedListQueue.h"

using namespace std;

void newLine() {
    cout << '\n';
}

int main()
{
    LinkedListQueue que; 
    int inputCapacity;
    cout << "[Initialize queue with capacity C (input by user)]\n";
    cin >> inputCapacity;
    que.init(inputCapacity);
    cout << "Capacity = " << que.getCapacity() << '\n';

    cout << "[Push to queue value 2, 5, 6]\n";
    que.enqueue(2);
    que.enqueue(5);
    que.enqueue(6);
  
    cout << "[Check if queue is full]\n";
    cout << "Full (0: false, 1: true) = " << que.isFull() << '\n';
    newLine();

    cout << "[Check if queue is empty]\n";
    cout << "Empty (0: false, 1: true) = " << que.isEmpty() << '\n';
    newLine();

    cout << "[Peek the head element of queue -> 2]\n";
    cout << "Head element: " << que.peek() << '\n';
    newLine();

    cout << "[Dequeue value 2 and 5]\n";
    cout << "Dequeue and receive value: " << que.dequeue() << '\n';
    cout << "Dequeue and receive value: " << que.dequeue() << '\n';
    newLine();

    cout << "[Get peek element (must be 6)]\n";
    cout << "Peek element = " << que.peek() << '\n';
    newLine();

    cout << "[Clear queue]\n";
    que.clear();
    newLine();

    cout << "[Get peek element again after clear]\n";
    int x = que.peek();
    cout << "Received value = " << x << " -> Empty!\n";
    newLine();

    cout << "[Check if queue is currently empty]\n";
    cout << "Empty (0: false, 1: true) = " << que.isEmpty() << '\n';
    newLine();

    return 0;
}
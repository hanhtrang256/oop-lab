#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream> 
#include <algorithm>
#include "Node.h"

class LinkedList {
private:
    Node* head;
    Node* tail;
    int num;
    double totalPrice; // <-- sum of total price of all nodes
public:
    /**
     * @brief Default constructor
     */
    LinkedList();

    /**
     * @brief Destructor 
     * @note delete head and tail
     */
    ~LinkedList();

    /**
     * @brief Add new Node
     * @param product new product
     */
    void addNode(const Product& product);

    /**
     * @brief Add new Node with specified quantity
     * @param product new product
     * @param quantity number of products
     */
    void addNode(const Product& product, const int& quantity);

    /**
     * @brief Delete a Node that has order id
     * @param id id of the node
     */
    void deleteNode(const int& id); 

    /**
     * @brief Clear linked list
     */
    void clear();

    /**
     * @brief Get current number of products
     * @note This function doesn't change any attributes
     */
    int getNum() const;

    /**
     * @brief Get total price of linked list (sum of total price of nodes)
     * @note This function doesn't change any attributes
     */
    double getTotalPrice() const;

    /**
     * @brief Get total price of only selected product
     */
    double getSelectedPrice() const;

    /**
     * @brief Adjust quantity of a node based on id
     * @param id id of a node
     * @param change +1 or -1
     */
    void adjustQuantity(const int& id, const int& change);

    /**
     * @brief Adjust selection type of a node based on id
     * @param id id of a node
     * @param select the new state
     */
    void adjustSelect(const int& id, bool select); 

    /**
     * @brief Print information of all nodes in order (id)
     */
    void output() const;
};

#endif // _LINKED_LIST_H_
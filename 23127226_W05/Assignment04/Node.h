#ifndef NODE_H
#define NODE_H

#include <iostream> 
#include <fstream>
#include "Product.h"

class Node {
private:
    Product product;
    Node* pNext;
    int quantity;
    double totalPrice; // <-- price of product * quantity
    bool select; // <-- selection state of the node
public:
    /**
     * @brief Default constructor
     * @note product is default to be empty
     * @param pNext default is nullptr
     */
    Node(); 

    /**
     * @brief Parameterized constructor
     * @param product
     * @param pNext default is nullptr
     */
    Node(const Product& product);

    /**
     * @brief Parameterized constructor
     * @param product product
     * @param quantity amount of product
     */
    Node(const Product& product, const int& quantity);

    /**
     * @brief Destructor
     * @note delete pointer pNext
     */
    ~Node();

    /**
     * @brief update product
     * @param product new product
     */
    void setProduct(const Product& product);

    /**
     * @brief Get product
     * @note This function doesn't change any attributes
     */
    Product getProduct() const;

    /**
     * @brief update pNext
     * @param pNext new pointer to next product
     */
    void setNext(Node* pNext);

    /**
     * @brief Get pNext
     * @note This function doesn't change any attributes
     */
    Node* getNext() const;

    /**
    * @brief Set quantity
    * @param quantity new quantity
     */
    void setQuantity(const int& quantity);

    /**
     * @brief Get quantity
     * @note This function doesn't change any attributes
     */
    int getQuantity() const;

    /**
     * @brief Adjust quantity
     * @param change +1 or -1
     */
    void adjustQuantity(const int& change);

    /**
     * @brief Get total price
     * @note This function doesn't change any attributes
     */
    double getTotalPrice() const;

    /**
     * @brief Set select state
     * @param select the state
     */
    void setSelect(bool select);

    /**
     * @brief Get selection state
     * @note This function doesn't change any attributes
     */
    bool getSelect() const;

    /**
     * @brief Print information of node
     * @param id order of the product (node) in list
     * @note This function doesn't change any attributes
     * @note format id. Product{info} | quantity: | totalPrice: | select: 
     */
    void output(const int& id) const;

    /**
     * @brief Print information of node into a file
     * @note This function doesn't change any attributes
     */
    void output(const int& id, std::ofstream &fout) const;

    void applyPromotion();
};

#endif // _NODE_H_
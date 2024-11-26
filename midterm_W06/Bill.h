#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "Product.h"

class Bill {
private:
    std::string id;
    std::string name;
    std::vector<Product> products;
public:
    // Default constructor
    Bill();

    // Parameterized constructor
    Bill(const std::string &id, const std::string &name);

    // Copy constructor
    Bill(const Bill &other);

    // Virtual destructor to delete allocated memory appropriate because this is abstract class
    virtual ~Bill() = default; 

    // single or inc type 
    virtual std::string getType() const = 0;

    // get total price
    virtual float getTotalPrice() const;

    // enter information of a bill
    virtual void input();

    // print information of a bill
    virtual void output();

    // set the ID for the bill
    void setID(const std::string &id);

    // get the ID of the bill
    std::string getID() const;

    // set the buyer's name for the bill
    void setName(const std::string &name);

    // get the buyer's name of the bill
    std::string getName() const;

    // set the set of products for the bill
    void setProducts(const std::vector<Product> &products);

    // add a product to bill
    void addProduct(const Product &product); 

    // get all products of the bill
    std::vector<Product> getProducts() const;
};

#endif 
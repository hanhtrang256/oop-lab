#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product {
private:
    std::string name;
    float price;
public:
    // Default constructor
    Product();

    // Parameterized constructor
    Product(const std::string &name, float price);

    // Copy constructor
    Product(const Product &other);

    // Enter information of the product
    void input();   

    // Print informatin of the product
    void output();

    // Set the name of product
    void setName(const std::string &name);

    // Get product's name
    std::string getName() const;

    // Set product's price
    void setPrice(float price);

    // Get product's price
    float getPrice() const;
};

#endif 
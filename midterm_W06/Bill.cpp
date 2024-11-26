#include "Bill.h"

Bill::Bill() : id(""), name(""), products({}) {}

Bill::Bill(const std::string &id, const std::string &name) : id(id), name(name), products({}) {}

Bill::Bill(const Bill &other) : id(other.id), name(other.id), products(other.products) {}

void Bill::setID(const std::string &id) {
    this->id = id;
}

std::string Bill::getID() const {
    return id;
}

void Bill::setName(const std::string &name) {
    this->name = name;
}

std::string Bill::getName() const {
    return name;
}

void Bill::setProducts(const std::vector<Product> &products) {
    this->products = products;
}

void Bill::addProduct(const Product &product) {
    this->products.push_back(product);
}

std::vector<Product> Bill::getProducts() const {
    return products;
}

float Bill::getTotalPrice() const {
    float tot = 0.0f;
    for (int i = 0; i < (int)products.size(); ++i) 
        tot += products[i].getPrice();
    return tot;
}

void Bill::input() {
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << "Name: ";
    std::cin >> name;
    int numProduct;
    std::cout << "Number of products: "; 
    std::cin >> numProduct;

    for (int i = 0; i < numProduct; ++i) {
        std::cout << "[Enter information of product " << i + 1 << "]\n";
        Product product;
        product.input();
        addProduct(product);
    }
}

void Bill::output() {
    std::cout << "[" << getType() << "-type bill]\n";
    std::cout << "ID: " << id << '\n';
    std::cout << "Name: " << name << '\n';
    for (int i = 0; i < (int)products.size(); ++i) {
        std::cout << "Product " << i + 1 << ":\n";
        products[i].output();
    }
    std::cout << "Total price: " << getTotalPrice() << '\n';
}

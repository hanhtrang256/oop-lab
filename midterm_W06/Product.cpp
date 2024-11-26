#include "Product.h"

Product::Product() : name(""), price(0.0f) {}

Product::Product(const std::string &name, float price) : name(name), price(price) {}

Product::Product(const Product &other) : name(other.name), price(other.price) {}

void Product::input() {
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Price: ";
    std::cin >> price;
}

void Product::output() {
    std::cout << "Name: " << name << '\n';
    std::cout << "Price: " << price << '\n';
}

void Product::setName(const std::string &name) {
    this->name = name;
}

std::string Product::getName() const {
    return name;
}

void Product::setPrice(float price) {
    this->price = price;
}

float Product::getPrice() const {
    return price;
}

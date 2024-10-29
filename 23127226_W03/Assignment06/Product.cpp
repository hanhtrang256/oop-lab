#include "Product.h"

/**
 * @brief Default constructor
 */
Product::Product() : name(""), shop(""), type(""), price(0.0) {}

/**
 * @brief Parameterized constructor
 */
Product::Product(const std::string& name, const std::string& shop, const std::string& type, const float& price) {
this->name = name;
this->shop = shop;
this->type = type;
this->price = price;
}

/**
 * @brief Copy constructor
 */
Product::Product(const Product& other) : name(other.name), shop(other.shop), type(other.type), price(other.price) {}

/** 
 * @brief set name of product
 */
void Product::setName(const std::string& name) { this->name = name; }

/**
 * @brief Get name of product
 * @note This function does not change attributes
 */
std::string Product::getName() const { return name; }

/** 
 * @brief set shop of product
 */
void Product::setShop(const std::string& shop) { this->shop = shop; }

/**
 * @brief Get shop of product
 * @note This function does not change attributes
 */
std::string Product::getShop() const { return shop; }

/** 
 * @brief set type of product (color, size, ...)
 */
void Product::setType(const std::string& type) { this->type = type; }

/**
 * @brief Get type of product
 * @note This function does not change attributes
 */
std::string Product::getType() const { return type; }

/** 
 * @brief set price of product
 */
void Product::setPrice(const float& price) { this->price = price; }

/**
 * @brief Get price of product
 * @note This function does not change attributes
 */
float Product::getPrice() const { return price; }

/**
 * @brief print information
 */
void Product::output() const {
    std::cout << "Product{name: " << name << "; shop: " << shop << "; type: " << type << "; price: " << price << "}";
}
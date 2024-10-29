#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <iostream>
#include <string>

class Product {
private:
    std::string name;
    std::string shop; 
    std::string type;
    float price;
public:
    /**
     * @brief Default constructor
     */
    Product(); 

    /**
     * @brief Parameterized constructor
     */
    Product(const std::string& name, const std::string& shop, const std::string& type, const float& price); 

    /**
     * @brief Copy constructor
     */
    Product(const Product& other);

    /** 
     * @brief set name of product
     */
    void setName(const std::string& name);

    /**
     * @brief Get name of product
     * @note This function does not change attributes
     */
    std::string getName() const; 

    /** 
     * @brief set shop of product
     */
    void setShop(const std::string& shop); 

    /**
     * @brief Get shop of product
     * @note This function does not change attributes
     */
    std::string getShop() const; 

    /** 
     * @brief set type of product (color, size, ...)
     */
    void setType(const std::string& type); 

    /**
     * @brief Get type of product
     * @note This function does not change attributes
     */
    std::string getType() const; 

    /** 
     * @brief set price of product
     */
    void setPrice(const float& price); 

    /**
     * @brief Get price of product
     * @note This function does not change attributes
     */
    float getPrice() const; 

    /**
     * @brief print information
     */
    void output() const;
};

#endif // _PRODUCT_H_
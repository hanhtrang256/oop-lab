#ifndef _USER_H_
#define _USER_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Product.h"

class User {
private:
  /**
  * @brief Store product's id
  * @note Each product in a specific user's cart has its own id (order) 
  **/
  std::map<Product, int> idOf;
  /**
  * @brief Trace the product based on id
  **/ 
  std::map<int, Product> productOf;
  /**
  * @brief Store information of the id (quantities, price, selection state) 
  **/
  std::map<int, std::pair<int, bool>> infoOf;
  int totalPrice; // <-- total price of all current product selected
  int idMax; // <-- Max number of id
public: 
  /**
  * @brief Default constructor
  * @note clear cart, set totalPrice to zero
  **/
  User();
  
  /**
  * @brief Get id of a product
  * @note Return -1 if not exist
  * This func doesn't change attributes
  **/
  int getID(const Product& product) const;
  
  /**
  * @brief Get product of corresponding id number
  * @note Return null if not exist
  * This func doesn't change attributes
  **/
  Product getProduct(const int& id) const;
  
  /**
  * @brief Get quantity of a product
  **/
  int getQuantity(const Product& product) const;

  /**
  * @brief Get quantity of an id
  **/
  int getQuantity(const int& id) const;
  
  /**
  * @brief Get selection state of a product
  **/
  bool getState(const Product& product) const;

  /**
  * @brief Get selection state of an id
  **/
  bool getState(const int& id) const;

  /**
  * @brief Add a product to cart
  * @note If product is new, add new id (closet id that does not have product)
  * @note Otherwise, update information for the corresponding id
  * @note Update totalPrice
  **/
  void addProduct(const Product& product);

  /**
  * @brief Output all to console
  **/
  void output();
};

#endif // _USER_H_

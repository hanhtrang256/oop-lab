#include "User.h"

/**
* @brief Default constructor
* @note clear cart, set totalPrice to zero
**/
User::User() {
  idOf.clear(); 
  productOf.clear();
  infoOf.clear(); 
  totalPrice = 0;
  idMax = 0;
}

/**
* @brief Get id of a product
* @note Return -1 if not exist
* This func doesn't change attributes
**/
int User::getID(const Product& product) const {
  if (idOf.find(product) != idOf.end()) 
    return idOf[product];
  return -1;
}

/**
* @brief Get product of corresponding id number
* @note Return empty product if not exist
* This func doesn't change attributes
**/
Product User::getProduct(const int& id) const {
  if (productOf.find(id) != productOf.end())
    return productOf[id]; 
  Product emp;
  return emp;
}

/**
* @brief Get quantity of a product
**/
int User::getQuantity(const Product& product) const {
  int id = getID(product); 
  if (id == -1) return 0; 
  return infoOf[id].first;
}

/**
* @brief Get quantity of an id
**/
int User::getQuantity(const int& id) const {
  if (infoOf.find(id) == infoOf.end()) return 0;
  return infoOf[id].first;
}

/**
* @brief Get selection state of a product
* @note return false by default if not exist
**/
bool User::getState(const Product& product) const {
  int id = getID(product);
  if (id == -1) return false; 
  return infoOf[id].second;
}

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


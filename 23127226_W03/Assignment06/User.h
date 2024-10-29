#ifndef _USER_H_
#define _USER_H_

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Product.h"

class User {
private:       
  LinkedList myList;
public: 
  /**
  * @brief Default constructor
  * @note clear cart, set totalPrice to zero
  **/
  User();
  
  /**
   * @brief Add a product
   * @note Asks user to enter information of the product
   */
  void addProduct();

  /**
   * @brief Delete a product with an id
   * @param id id to delete
   */
  void delProduct(const int& id);

  /**
   * @brief Adjust quantity of a product
   * @param id id of a product to adjust
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
   * @brief Get total price of all products
   * @note This function doesn't change any attributes
   */
  double getTotalPrice() const;

  /**
   * @brief Get total price of only selected product
   */
  double getSelectedPrice() const;

  /**
  * @brief Output all products to console
  **/
  void output() const;
};

#endif // _USER_H_

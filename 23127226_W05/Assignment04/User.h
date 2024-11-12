#ifndef _USER_H_
#define _USER_H_

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <fstream>
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
	 * @brief Add a product with information and quantity already
	 */
	void addProduct(const Product &product, int quantity);

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

	/**
	 * @brief Load product from a file
	 */
	void loadFile(std::string filename);

	/**
	 * @brief Save all orders into order.txt file
	 * @note This function doesn't change any attributes 
	 */
	void saveOrders() const;

	/**
	 * @brief Apply promotion to a product based on id
	 */
	void applyPromotion(int id);
};

#endif // _USER_H_

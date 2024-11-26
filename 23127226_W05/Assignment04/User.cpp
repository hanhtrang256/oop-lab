#include "User.h"

/**
* @brief Default constructor
* @note clear cart, set totalPrice to zero
**/
User::User() : myList(LinkedList()) {}

/**
 * @brief Add a product
 * @note Asks user to enter information of the product
 * @note Add new product to linked list
 */
void User::addProduct() {
  	std::cout << "Product name: "; 
  	std::string name; 
  	std::cin >> name; 

  	std::cout << "Shop: "; 
  	std::string shop; 
  	std::cin >> shop;

  	std::cout << "Type: "; 
  	std::string type;
  	std::cin >> type;

  	std::cout << "Price: "; 
  	float price;
  	std::cin >> price;

  	Product product(name, shop, type, price);
  	myList.addNode(product);
}

void User::addProduct(const Product &product, int quantity) { myList.addNode(product, quantity); }

/**
 * @brief Delete a product with an id
 * @param id id to delete
 */
void User::delProduct(const int& id) { myList.deleteNode(id); }

/**
 * @brief Adjust quantity of a product
 * @param id id of a product to adjust
 * @param change +1 or -1 
 */
void User::adjustQuantity(const int& id, const int& change) {
  	myList.adjustQuantity(id, change);
}

/**
 * @brief Adjust selection type of a node based on id
 * @param id id of a node
 * @param select the new state
 */
void User::adjustSelect(const int& id, bool select) {
  	myList.adjustSelect(id, select);
}


/**
 * @brief Get total price of all products
 * @note This function doesn't change any attributes
 */
double User::getTotalPrice() const {
  	return myList.getTotalPrice();
}

/**
 * @brief Get total price of only selected product
 */
double User::getSelectedPrice() const {
  	return myList.getSelectedPrice();
}

/**
* @brief Output all products to console
**/
void User::output() const {
  	myList.output();
}
/**
 * @brief Load product from a file
 */
void User::loadFile(std::string filename) {
	std::ifstream fin(filename.c_str());
	std::string name, shop, type;
	std::string priceStr, quanStr;
	float price;
	int quantity;

	while (getline(fin, name)) {
		if (name.empty()) continue;
		getline(fin, shop);
		getline(fin, type);
		getline(fin, priceStr);
		getline(fin, quanStr);
		std::cout << name << '\n' << shop << '\n' << type << '\n' << priceStr << '\n' << quanStr << '\n';
		std::stringstream buffer(priceStr);
		buffer >> price;
		buffer.str("");
		buffer.str(quanStr);
		buffer >> quantity;
		addProduct(Product(name, shop, type, price), quantity);
	}

	fin.close();
}

/**
 * @brief Save all orders into order.txt file
 * @note This function doesn't change any attributes 
 */
void User::saveOrders() const {
	myList.output("orders.txt");
}

void User::applyPromotion(int id) {
	myList.applyPromotion(id);
}
#include "Node.h"

/**
 * @brief Default constructor
 * @note product is default to be empty
 * @param pNext default is nullptr
 */
Node::Node() : product(Product()), pNext(nullptr), quantity(0), totalPrice(0.0), select(false) {}

/**
 * @brief Parameterized constructor
 * @param product
 * @param pNext default is nullptr
 */
Node::Node(const Product& product) : product(product), pNext(nullptr), quantity(1), totalPrice(product.getPrice()), select(false) {}

/**
 * @brief Parameterized constructor
 * @param product product
 * @param quantity amount of product
 */
Node::Node(const Product& product, const int& quantity) : product(product), pNext(nullptr), quantity(quantity), 
                                                totalPrice(product.getPrice() * (float)quantity), select(false) {}

/**
 * @brief Destructor
 * @note delete pointer pNext
 */
Node::~Node() { delete pNext; }

/**
 * @brief update product
 * @param product new product
 */
void Node::setProduct(const Product& product) { this->product = product; }

/**
 * @brief Get product
 * @note This function doesn't change any attributes
 */
Product Node::getProduct() const { return this->product; }

/**
 * @brief update pNext
 * @param pNext new pointer to next product
 */
void Node::setNext(Node* pNext) { this->pNext = pNext; }

/**
 * @brief Get pNext
 * @note This function doesn't change any attributes
 */
Node* Node::getNext() const { return this->pNext; }

/**
* @brief Set quantity
* @param quantity new quantity
*/
void Node::setQuantity(const int& quantity) { this->quantity = quantity; }

/**
 * @brief Get quantity
 * @note This function doesn't change any attributes
 */
int Node::getQuantity() const { return quantity; }

/**
 * @brief Adjust quantity
 * @param change +1 or -1
 */
void Node::adjustQuantity(const int& change) {
    setQuantity(std::max(1, quantity + change));
    if (change == +1) totalPrice += product.getPrice();
    else {
        if (quantity > 1) 
            totalPrice -= product.getPrice();
    }
}

/**
 * @brief Get total price
 * @note This function doesn't change any attributes
 */
double Node::getTotalPrice() const { return totalPrice; }

/**
 * @brief Set select state
 * @param select the state
 */
void Node::setSelect(bool select) { this->select = select; }

/**
 * @brief Get selection state
 * @note This function doesn't change any attributes
 */
bool Node::getSelect() const { return select; }

/**
 * @brief Print information of node
 * @note This function doesn't change any attributes
 * @note format id. Product{info} | quantity: | totalPrice: | select: 
 */
void Node::output(const int& id) const {
    std::cout << id << ". "; 
    product.output();
    std::cout << " | quantity: " << quantity << " | total price: " << totalPrice << " | select: " << select;
}

void Node::output(const int &id, std::ofstream &fout) const {
    fout << id << ". "; 
    product.output(fout);
    fout << " | quantity: " << quantity << " | total price: " << totalPrice << " | select: " << select;
}

void Node::applyPromotion() {
    totalPrice /= 2.0f;
}

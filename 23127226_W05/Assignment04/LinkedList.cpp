#include "LinkedList.h"

/**
 * @brief Default constructor
 */
LinkedList::LinkedList() : head(nullptr), tail(nullptr), num(0), totalPrice(0.0) {}

/**
 * @brief Destructor 
 * @note delete head and tail
 */
LinkedList::~LinkedList() { 
    clear();
    head = nullptr;
    tail = nullptr;
    // std::cout << "~LinkedList()\n";
}

/**
 * @brief Add new Node
 * @param product new product
 * @note new product will be added to tail of linked list
 */
void LinkedList::addNode(const Product& product) {
    Node* newNode = new Node(product);
    ++num;
    totalPrice += newNode->getTotalPrice();
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->setNext(newNode); 
    tail = newNode;
}

/**
 * @brief Add new Node with specified quantity
 * @param product new product
 * @param quantity number of products
 */
void LinkedList::addNode(const Product& product, const int& quantity) {
    Node* newNode = new Node(product, quantity);
    ++num; 
    totalPrice += newNode->getTotalPrice();
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->setNext(newNode); 
    tail = newNode;
}

/**
 * @brief Delete a Node that has order id
 * @param id id of the node
 * @note TODO: update num, totalPrice, head, tail carefully
 */
void LinkedList::deleteNode(const int& id) {
    if (head == nullptr) return; // <-- linked list is empty
    if (num == 1) { // <-- linked list has 1 node
        if (id != 1) return; // <-- id does not match the element in linked list
        delete head;
        head = nullptr;
        tail = nullptr;  
        num = 0;
        totalPrice = 0.0;
        return;
    }
    if (id > num || id < 0) return; // <-- invalid id

    if (id == 1) { // <-- delete head
        Node* tmp = head->getNext();
        --num; 
        totalPrice -= head->getTotalPrice();
        delete head;
        head = tmp;  
        return;
    }

    int it = 1;
    Node* cur = head;
    Node* prev = nullptr;
    while (cur != nullptr) {
        if (it == id) {
            --num;
            totalPrice -= cur->getTotalPrice();
            
            prev->setNext(cur->getNext()); // <-- prev can't be nullptr because that case only occurs when we are deleting head (already above)
            if (cur == tail) tail = prev; // <-- if deleted node is tail, shift tail to previous node            
            cur->setNext(nullptr); // <-- pNext of cur is still pointing to the next memory, if delete cur -> next memory will also be deleted
                                   // <-- So we must set next pointer of cur to nullptr before delete it
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->getNext();
        ++it;
    }
}

/**
 * @brief Clear linked list
 */
void LinkedList::clear() {
    while (num > 0) 
        deleteNode(1);
}

/**
 * @brief Get current number of products
 * @note This function doesn't change any attributes
 */
int LinkedList::getNum() const { return num; }

/**
 * @brief Get total price of linked list (sum of total price of nodes)
 * @note This function doesn't change any attributes
 */
double LinkedList::getTotalPrice() const { return totalPrice; }

/**
 * @brief Get total price of only selected product
 */
double LinkedList::getSelectedPrice() const {
  double tot = 0.0;
  if (head == nullptr) return tot;
  Node* cur = head;
  while (cur != nullptr) {
    if (cur->getSelect() == true) {
        tot = tot + cur->getTotalPrice();
    }
    cur = cur->getNext();
  }
  return tot;
}

/**
 * @brief Adjust quantity of a node based on id
 * @param id id of a node
 * @param change +1 or -1
 */
void LinkedList::adjustQuantity(const int& id, const int& change) { 
    if (id < 0 || id > num) return;
    if (head == nullptr) return; 

    int it = 1;
    Node* cur = head;
    while (cur != nullptr) {
        if (it == id) {
            cur->adjustQuantity(change);
            break;
        }
        cur = cur->getNext();
        ++it;
    }
}

/**
 * @brief Adjust selection type of a node based on id
 * @param id id of a node
 * @param select the new state
 */
void LinkedList::adjustSelect(const int& id, bool select) {
    if (id < 0 || id > num) return;
    if (head == nullptr) return; 

    int it = 1;
    Node* cur = head;
    while (cur != nullptr) {
        if (it == id) {
            cur->setSelect(select);
            break;
        }
        cur = cur->getNext();
        ++it;
    }
}

/**
 * @brief Print information of all nodes in order (id)
 */
void LinkedList::output() const {
    if (head == nullptr) return;
    int id = 1; 
    Node* cur = head;
    while (cur != nullptr) {
        cur->output(id);
        std::cout << '\n';
        cur = cur->getNext();
        ++id;
    }
}

/**
 * @brief Print information of all nodes into a file
 */
void LinkedList::output(std::string filename) const {
    if (head == nullptr) return;
    std::ofstream fout(filename.c_str());
    int id = 1; 
    Node* cur = head;
    while (cur != nullptr) {
        cur->output(id, fout);
        fout << '\n';
        cur = cur->getNext();
        ++id;
    }
    fout.close();
}

void LinkedList::applyPromotion(int id) {
    if (head == nullptr) return;
    int it = 1;
    Node *cur = head;
    while (cur != nullptr) {
        if (it == id) {
            cur->applyPromotion();
            break;
        }
        ++it;
        cur = cur->getNext();
    }
}

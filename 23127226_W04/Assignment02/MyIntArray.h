#ifndef _MY_INT_ARRAY_H_
#define _MY_INT_ARRAY_H_

#include <iostream>
#include <string>

class myIntArray {
private:
    int n;
    int* a;
public:
    /**
     * @brief Default constructor for array
     */
    myIntArray(); 

    /**
     * @brief Parameterized constructor
     * @param n input size 
     */
    myIntArray(int n); 

    /**
     * @brief Parameterized constructor
     * @param n new size
     * @param a new pointer
     * @note perform deep copy
     */
    myIntArray(int n, int *a);

    /**
     * @brief Parameterized constructor
     * @param s string. Format: n a0 a1 a2 ... an-1
     */
    myIntArray(std::string s);

    /**
     * @brief Copy constructor (must specify because has dynamic memory allocated)
     * @param other same-class object to copy
     * @note perform deep copy
     */
    myIntArray(const myIntArray& other);

    /**
     * @brief Move constructor
     * @param other temporary same-class object
     * @note move all the content of other to current
     * @note set the pointer of other to nullptr
     * @note noexception
     */
    myIntArray(myIntArray&& other) noexcept;

    /**
     * @brief Destructor
     * @note delete a pointer
     */
    ~myIntArray();

    /**
     * @brief Some basic methods for array
     * @note modify value at index i with value x
     * @note reset array to value x
     * @note input array  
     * @note output array
     * @note toString()
     * @note clone()
     * @note getN() 
     * @note getA()
     */
    void modify(int i, int x); 
    void reset(int x);
    void input();
    void output();
    std::string toString();
    myIntArray clone(const myIntArray& other); 
    int getN(); 
    int* getA();

    /**
     * @brief Arithmetic Operators
     */
    friend std::ostream& operator << (std::ostream& out, const myIntArray& other);
    friend std::istream& operator >> (std::istream& in, myIntArray& other);
    myIntArray& operator = (const myIntArray& other);
    myIntArray operator + (const myIntArray& other) const;
    myIntArray operator + (const int& other) const; // plus other to all number in array
    friend myIntArray operator + (const int& num, const myIntArray& other); // plus other to all number in array
    myIntArray& operator += (const myIntArray& other);
    myIntArray operator - (const myIntArray& other) const;
    myIntArray operator - (const int& other) const;
    friend myIntArray operator - (const int& num, const myIntArray& other);
    myIntArray& operator -= (const myIntArray& other);
    myIntArray operator * (const myIntArray& other) const;
    myIntArray operator * (const int& other) const;
    friend myIntArray operator * (const int& num, const myIntArray& other);
    myIntArray& operator *= (const myIntArray& other);
    myIntArray operator / (const int& other) const;
    myIntArray& operator /= (const int& other);

    /**
     * @brief Relational Operators
     */
    bool operator == (const myIntArray& other) const;
    bool operator != (const myIntArray& other) const;
    bool operator > (const myIntArray& other) const;
    bool operator < (const myIntArray& other) const;

    /**
     * @brief Incremental, Decremental operators
     */
    myIntArray& operator ++ (); // plus all element by 1
    myIntArray operator ++ (int); 
    myIntArray& operator -- (); // minus all element by 1
    myIntArray operator -- (int); 

    /**
     * @brief Casting 
     */
    operator int() const;

    /**
     * @brief get index of array operator
     */
    int& operator[](int) const;
};

#endif // _MY_INT_ARRAY_H_

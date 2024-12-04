#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <string>
#include <sstream>
#include <algorithm>

template <class T>
class MyVector {
private:
    T *arr;
    int size;
    void resize(int newSize);
public:
    // empty array
    MyVector();
    // n zeros
    MyVector(int n);
    MyVector(T *a, int n);
    MyVector(const MyVector &v);
    ~MyVector();
    int getSize();
    T getItem(int index);
    void setItem(T value, int index);
    void add(T value);
    void addRange(T *a, int n);
    void clear();
    bool contains(T value);
    void toArray(T *arr, int &n);
    bool equals(const MyVector &v);
    int indexOf(T value);
    int lastIndexOf(T value);
    void insert(T value, int index);
    void remove(T value);
    void removeAt(int index);
    void reverse();
    std::string toString();
    void sortAsc();
    void sortDesc();
};

template <class T>
inline void MyVector<T>::resize(int newSize) {
    if (arr == nullptr) {
        arr = new T[newSize];
        for (int i = 0; i < newSize; ++i) arr[i] = T();
        size = newSize;
        return;
    }
    T *temp = new T[newSize];
    for (int i = 0; i < std::min(size, newSize); ++i) temp[i] = arr[i];
    for (int i = size; i < newSize; ++i) temp[i] = T();
    delete[] arr;
    arr = temp;
    size = newSize;
}

template <class T>
inline MyVector<T>::MyVector() : arr(nullptr), size(0) {}

template <class T>
inline MyVector<T>::MyVector(int n) : arr(new T[n]), size(n) {}

template <class T>
inline MyVector<T>::MyVector(T *a, int n) {
    // Perform deep copy for memory safety
    // delete[] arr; // in case it is already pointing to some allocated memory
    arr = new T[n];
    for (int i = 0; i < n; ++i) arr[i] = a[i];
    size = n;
}

template <class T>
inline MyVector<T>::MyVector(const MyVector &v) {
    if (v.arr == nullptr) throw std::runtime_error("null pointer");
    // delete[] arr; // in case it is already pointing to some allocated memory
    arr = new T[v.getSize()];
    for (int i = 0; i < v.getSize(); ++i) arr[i] = v.getItem(i);
    size = v.getSize();
}

template <class T>
inline MyVector<T>::~MyVector() { 
    delete[] arr; 
    std::cout << "Delete pointer arr!!!\n";
}

template <class T>
inline int MyVector<T>::getSize() { return size; }

template <class T>
inline T MyVector<T>::getItem(int index) {
    if (index < 0 || index >= size) {
        throw std::runtime_error("segmentation fault");
    }
    return arr[index]; 
}

template <class T>
inline void MyVector<T>::setItem(T value, int index) {
    if (index < 0 || index >= size) throw std::runtime_error("segmentation fault");
    arr[index] = value;
}

template <class T>
inline void MyVector<T>::add(T value) {
    resize(size + 1);
    arr[size - 1] = value;
}

template <class T>
inline void MyVector<T>::addRange(T *a, int n) {
    resize(size + n);
    for (int i = size - n; i < size; ++i)
        arr[i] = a[i - (size - n)];
}

template <class T>
inline void MyVector<T>::clear() {
    if (arr == nullptr) return;
    for (int i = 0; i < size; ++i) arr[i] = T();
}

template <class T>
inline bool MyVector<T>::contains(T value) {
    if (arr == nullptr) return false;
    for (int i = 0; i < size; ++i) 
        if (arr[i] == value)
            return true;
    return false;
}

template <class T>
inline void MyVector<T>::toArray(T *_arr, int &n) {
    n = size;
    for (int i = 0; i < size; ++i) _arr[i] = arr[i];
}

template <class T>
inline bool MyVector<T>::equals(const MyVector &v) {
    if (arr == nullptr || v.arr == nullptr) throw std::runtime_error("null pointer");
    for (int i = 0; i < size; ++i) 
        if (arr[i] != v.arr[i])
            return false;
    return true;
}

template <class T>
inline int MyVector<T>::indexOf(T value) {
    if (arr == nullptr) {
        throw std::runtime_error("null pointer");
    }
    for (int i = 0; i < size; ++i) 
        if (arr[i] == value)
            return i;
    return size;
}

template <class T>
inline int MyVector<T>::lastIndexOf(T value) {
    if (arr == nullptr) throw std::runtime_error("null pointer");
    for (int i = size - 1; i >= 0; --i) 
        if (arr[i] == value)
            return i;
    return size;
}

template <class T>
inline void MyVector<T>::insert(T value, int index) {
    if (index < 0 || index >= size) throw std::runtime_error("segmentation fault");
    resize(size + 1);
    std::cout << "size = " << size << '\n';
    for (int i = size - 1; i > index; --i) arr[i] = arr[i - 1];
    arr[index] = value;
}

template <class T>
inline void MyVector<T>::remove(T value) {
    if (arr == nullptr) return;
    int cnt = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            for (int j = i; j < size - 1; ++j) 
                arr[j] = arr[j + 1];
            ++cnt;
        }
    }
    if (cnt != 0) resize(size - cnt);
}

template <class T>
inline void MyVector<T>::removeAt(int index) {
    if (index < 0 || index >= size) throw std::runtime_error("segmentation fault");
    for (int i = index; i < size - 1; ++i) 
        arr[i] = arr[i + 1];
    resize(size - 1);
}

template <class T>
inline void MyVector<T>::reverse() {
    if (arr == nullptr) return;
    T *temp = new T[size];
    for (int i = size - 1; i >= 0; --i) temp[size - i - 1] = arr[i];
    delete[] arr;
    arr = temp;
}

template <class T>
inline std::string MyVector<T>::toString() {
    std::stringstream buffer;
    buffer.str(std::string(100, '\0'));
    buffer.clear();
    buffer << "{n = " << size << ":";
    for (int i = 0; i < size; ++i) {
        buffer << " ";
        buffer << arr[i];
        if (buffer.fail()) {
            throw std::runtime_error("Fail stringstream");
        }
        // std::cout << " " << arr[i];
        // std::cout << arr[i] << '\n';
    }
    buffer << "}";
    // std::cout << '\n';
    return buffer.str();
}

template <class T>
inline void MyVector<T>::sortAsc() {
    if (arr == nullptr) return;
    std::sort(arr, arr + size); // <-- need to define < operator in class T
}

template <class T>
inline void MyVector<T>::sortDesc() {
    if (arr == nullptr) return;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] < arr[j]) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // std::sort(arr, arr + size, std::greater<T>()); --> need to define > operator in class T
}

#endif // MYVECTOR_H

#include <iostream>
#include <cstring>
using namespace std;

class A {
private:
    char *m_s;
public:
    A() { m_s = strcpy(m_s, "default"); }
    A(char *s) {
        /* OLD CODE */ 
        //m_s = s; --> shallow copy
        /* -------- */

        /* NEW CODE */
        m_s = new char[strlen(s) + 1];
        for (int i = 0; i < strlen(s); ++i) m_s[i] = s[i];
        m_s[strlen(s)] = '\0';
        /* -------- */
    }
    /* NEW CODE */
    A(const A &other) {
        m_s = new char[strlen(other.m_s) + 1];
        for (int i = 0; i < strlen(other.m_s); ++i) m_s[i] = other.m_s[i];
        m_s[strlen(other.m_s)] = '\0';
    }
    virtual ~A() { // At first, no destructor to delete allocated memory 
        // Needs to be virtual to properly delete subclass
        delete m_s; 
    }
    friend istream &operator >> (istream &in, A &a);
    friend ostream &operator << (ostream &out, const A &a);
    /* -------- */
    virtual void prepare() { cout << "A "; }
    void display() {
        prepare();
        cout << m_s << endl;
    }
};

class B : public A {
public:
    B(char *s) : A(s) {}
    B(const B &b) : A(b) { 
        // At first, it is empty so it will call default constructor of A
        // Now to copy, we need to to perform deep copy for it
        // Since we cannot access m_s, we will write copy constructor for A class then reuse it in B
    }
    void prepare() { cout << "B "; }
    /* NEW CODE */
    friend istream &operator >> (istream &in, B &b);
    friend ostream &operator << (ostream &out, const B &b);
    /* -------- */
};

istream &operator>>(istream &in, A &a) {
    in >> a.m_s;
    return in;
}

ostream &operator<<(ostream &out, const A &a)
{
    out << a.m_s;
    return out;
}

istream &operator>>(istream &in, B &b){
    return in;
}

ostream &operator<<(ostream &out, const B &b) {
    return out;
}

void foo(A *obj1, A obj2) {
    obj1->display();
    obj2.display();
}

int main() {
    B obj1("text");
    A *obj2 = new B(obj1);
    foo(&obj1, *obj2);
    delete obj2; // at first, no delete -> memory leaks
    return 0;
}



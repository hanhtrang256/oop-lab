#include <iostream>
#include <algorithm>
#include "MyVector.h"
#include "Fraction.h"

void integerVector() {
    std::cout << "---------------- INTEGER VECTOR ----------------\n";
    MyVector<int> a;
    try { std::cout << a.getItem(25) << '\n'; }
    catch (const std::exception &error) { std::cout << error.what() << '\n'; }

    std::cout << "[ADDING 25 AND 6 TO VECTOR a]\n";
    a.add(25);
    a.add(6);

    std::cout << "[TO STRING OF VECTOR a]\n";
    std::cout << a.toString() << '\n';

    std::cout << "[GET SIZE]\n";
    std::cout << a.getSize() << '\n';

    std::cout << "[GET ITEM AT INDEX 1 --> 6]\n";
    try { std::cout << a.getItem(1) << '\n'; }
    catch (const std::exception &error) { std::cout << error.what() << '\n'; }

    std::cout << "[ADD A RANGE --> 3 0 4]\n";
    int range[3] = {3, 0, 4};
    a.addRange(range, 3);
    std::cout << a.toString() << '\n';

    std::cout << "[TRY GET ITEM AT INDEX 5 --> segmentation fault]\n";
    try { std::cout << a.getItem(5) << '\n'; }
    catch (const std::exception &error) { std::cout << error.what() << '\n'; }
    
    std::cout << "[CHECK IF VECTOR a CONTAINS 3 --> True]\n";
    std::cout << a.contains(3) << '\n';

    std::cout << "[CONVERT FROM VECTOR a to ARRAY b]\n";
    int b[25], n = 0;
    a.toArray(b, n);
    std::cout << "n = " << n << '\n';
    std::cout << "Array b: ";
    for (int i = 0; i < n; ++i) std::cout << b[i] << " ";
    std::cout << '\n';

    std::cout << "[COMPARE Vector a to VECTOR c (3, 0, 4) --> false]\n";
    MyVector<int> c(range, 3);
    std::cout << "To String of vector c: " << c.toString() << '\n';
    // std::cout << a.equals(c) << '\n';

    std::cout << "[FIND FIRST INDEX OF VALUE 4 --> 4]\n";
    try { std::cout << a.indexOf(4) << '\n'; }
    catch (const std::exception &error) { std::cout << error.what() << '\n'; }

    std::cout << "[INSERT VALUE 5 TO INDEX 2 --> 25 6 5 3 0 4]\n";
    a.insert(5, 2);
    std::cout << "To string of vector a: " << a.toString() << '\n';

    std::cout << "[SORT ASCENDING VECTOR a --> 0 3 4 5 6 25]\n";
    a.sortAsc();
    std::cout << "To string of vector a: " << a.toString() << '\n';

    std::cout << "[SORT DESCENDING VECTOR a --> 25 6 5 4 3 0]\n";
    a.sortDesc();
    std::cout << "To string of vector a: " << a.toString() << '\n';

    std::cout << "[REMOVE VALUE 5 --> 25 6 4 3 0]\n";
    a.remove(5);
    std::cout << "To string of vector a: " << a.toString() << '\n';

    std::cout << "[REMOVE VALUE AT INDEX 3 --> 25 6 4 0]\n";
    a.removeAt(3);
    std::cout << "To string of vector a: " << a.toString() << '\n';

    std::cout << "[REVERSE THE VECTOR --> 0 4 6 25]\n";
    a.reverse();
    try { std::cout << "To string of vector a: " << a.toString() << '\n'; }
    catch (const std::exception &error) { std::cout << error.what() << '\n'; }
}

void fractionVector() {
    std::cout << "---------------- FRACTION VECTOR ----------------\n";
    MyVector<Fraction> fracs;
    try { std::cout << fracs.getItem(25) << '\n'; }
    catch (const std::exception &error) { std::cout << error.what() << '\n'; }

    std::cout << "[ADDING 2/5 AND 6/1 TO VECTOR fracs]\n";
    fracs.add(Fraction(2, 5));
    fracs.add(Fraction(6, 1));

    std::cout << "[TO STRING OF VECTOR fracs]\n";
    std::cout << fracs.toString() << '\n';

    std::cout << "[GET SIZE]\n";
    std::cout << fracs.getSize() << '\n';

    std::cout << "[GET ITEM AT INDEX 1 --> 6/1]\n";
    try { std::cout << fracs.getItem(1) << '\n'; }
    catch (const std::exception &error) { std::cout << error.what() << '\n'; }

    std::cout << "[ADD A RANGE --> 3/5 0/2 4/7]\n";
    Fraction rangeF[3] = {Fraction(3, 5), Fraction(0, 2), Fraction(4, 7)};
    fracs.addRange(rangeF, 3);
    std::cout << fracs.toString() << '\n';

    std::cout << "[TRY GET ITEM AT INDEX 5 --> segmentation fault]\n";
    try { std::cout << fracs.getItem(5) << '\n'; }
    catch (const std::exception &error) { std::cout << error.what() << '\n'; }
    
    std::cout << "[CHECK IF VECTOR fracs CONTAINS 3/5 --> True]\n";
    std::cout << fracs.contains(Fraction(3, 5)) << '\n';

    std::cout << "[CONVERT FROM VECTOR fracs to ARRAY x]\n";
    Fraction x[25];
    int n2 = 0;
    fracs.toArray(x, n2);
    std::cout << "n = " << n2 << '\n';
    std::cout << "Array x: ";
    for (int i = 0; i < n2; ++i) std::cout << x[i] << " ";
    std::cout << '\n';

    std::cout << "[COMPARE Vector fracs to VECTOR d (3/5, 0/2, 4/7) --> false]\n";
    MyVector<Fraction> d(rangeF, 3);
    std::cout << "To String of vector d: " << d.toString() << '\n';
    std::cout << fracs.equals(d) << '\n';

    std::cout << "[FIND FIRST INDEX OF VALUE 4/7 --> 4]\n";
    std::cout << fracs.indexOf(Fraction(4, 7)) << '\n';

    std::cout << "[INSERT VALUE 5/6 TO INDEX 2 --> 2/5 6/1 5/6 3/5 0/2 4/7]\n";
    fracs.insert(Fraction(5, 6), 2);
    std::cout << "To string of vector fracs: " << fracs.toString() << '\n';

    std::cout << "[SORT ASCENDING VECTOR fracs]\n";
    fracs.sortAsc();
    std::cout << "To string of vector fracs: " << fracs.toString() << '\n';

    std::cout << "[SORT DESCENDING VECTOR fracs]\n";
    fracs.sortDesc();
    std::cout << "To string of vector fracs: " << fracs.toString() << '\n';

    std::cout << "[REMOVE VALUE 5/6]\n";
    fracs.remove(Fraction(5, 6));
    std::cout << "To string of vector fracs: " << fracs.toString() << '\n';

    std::cout << "[REMOVE VALUE AT INDEX 3]\n";
    fracs.removeAt(3);
    std::cout << "To string of vector fracs: " << fracs.toString() << '\n';

    std::cout << "[REVERSE THE VECTOR]\n";
    fracs.reverse();
    std::cout << "To string of vector fracs: " << fracs.toString() << '\n';

}

int main() {
    integerVector();
    fractionVector();
    return 0;
}
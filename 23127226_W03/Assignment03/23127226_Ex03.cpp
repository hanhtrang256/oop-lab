#include "MyIntArray.h"
#include <iostream>
#include <algorithm>
#include <string>

int main() {
	std::cout << "[Create arr1 with default constructor]\n";
	myIntArray arr1; 	
           	
	std::cout << "[Create arr2 with parameter 6]\n";
	myIntArray arr2(6); 

	std::cout << "[Create arr3 with parameter 4 and pointer array *b]\n";
	int* b = new int[4]; 
	b[0] = 1; b[1] = 2; b[2] = 3; b[3] = 4;
	std::cout << "array b is "; 
	for (int i = 0; i < 4; ++i)
		std::cout << b[i] << " ";
	std::cout << '\n';
	myIntArray arr3(4, b); 
	std::cout << "arr3 = "; 
	arr3.output();
	std::cout << '\n';

	std::cout << "[Create arr4 with parameter string format]\n"; 
	std::string s = "3 2 5 6"; 
	std::cout << "string s = " << s << '\n';
	myIntArray arr4(s); 
	std::cout << "arr4 = "; 
	arr4.output();
	std::cout << '\n';

	std::cout << "[Create arr5 copy from arr3 (deep copy)]\n";
	myIntArray arr5(arr3); 
	std::cout << "arr5 = "; 
	arr5.output();

	std::cout << "[Create arr6 move from arr4]\n";
	myIntArray arr6 = std::move(arr4); 
	std::cout << "arr4 = "; arr4.output(); 
	std::cout << "arr6 = "; arr6.output(); 

	std::cout << "[Modify last element of arr6]\n"; 
	arr6.modify(arr6.getN() - 1, 2); 
	std::cout << "arr6 = "; arr6.output(); 
	
	std::cout << "[Convert arr6 to string]\n"; 
	std::string convr = arr6.toString(); 
	std::cout << "Converted string is " << convr << '\n';

	std::cout << "[Reset arr6 to all 0]\n";
	arr6.reset(0); 
	std::cout << "arr6 = "; 
	arr6.output();

	delete b;
	std::cout << "---- [Destructor called] ----";
  return 0;
}

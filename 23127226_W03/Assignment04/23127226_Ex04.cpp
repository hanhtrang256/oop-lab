#include <iostream>
#include <string> 
#include <cstring>
#include "Student.h"


int main() {
	std::cout << "\n[Create Student0 with no information -> default constructor]\n";
	Student stu0; 

	std::cout << "\n[Create Student1 full information -> parameterized constructor]\n";
	Student stu1(23127226, "Nguyen Dang Minh", "HCMUS", 10.0);
	std::cout << "Student1: ";
	stu1.output();

	std::cout << "\n[Create Student2 based on string -> parameterized constructor]\n";
	std::string s = "256256 TRANG HCMIU 10.0"; 
	Student stu2(s);
	std::cout << "Student2: ";
	stu2.output();

	std::cout << "\n[Create Student3 copy from Student1 -> copy constructor]\n";
	Student stu3(stu1);
	std::cout << "Student3: ";
	stu3.output();

	std::cout << "\n[Create Student4 by move from Student2 -> move constructor]\n";
	Student stu4 = std::move(stu2); 
	std::cout << "Student2: "; 
	stu2.output();
	std::cout << "Student4: ";
	stu4.output(); 

	std::cout << "\n[Create Student5 clone from Student1]\n"; 
	Student stu5 = stu1.clone(); 
	std::cout << "Student5: ";
	stu5.output();
	
	std::cout << "\n[String format of Student 1]\n"; 
	std::string stu1Str = stu1.toString();
	std::cout << stu1Str << '\n';

	return 0;
}

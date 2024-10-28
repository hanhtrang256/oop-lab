#include "Student.h" 
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iostream>

/**
* @brief a convenient function to copy array b to a 
* @param a is passed by reference
* @note handle the '\0' at end
* @note make sure the b parameter is correct-format char array and has the '\0'
* before pass it
**/
void Student::copyCharArr(char*& a, const char* b) {
	int m = (int)strlen(b); 
	if (m == 0) return; 
	a = new char[m + 1];
	for (int i = 0; i < m; ++i) 
		a[i] = b[i];
	a[m] = '\0';
}

/**
* @brief Default constructor
* @param no parameter, all set to 0 or nullptr
**/
Student::Student() : id(0), fullname(nullptr), address(nullptr), gpa(0.0) {
	std::cout << "Student::Student() default constructor\n"; 
}

/**
* @brief Parameterized constructor
* @param _id student id 
* @param _fullname fullname of student
* @param _address student's address
* @param _gpa student's gpa
* @note perform deep copy so that it won't conflict with outside-scope pointer
**/
Student::Student(int _id, const char* _fullname, const char* _address, double _gpa) {
	id = _id; 
	
	fullname = new char[strlen(_fullname) + 1]; 
	for (int i = 0; i < strlen(_fullname); ++i) 
		fullname[i] = _fullname[i];
	fullname[strlen(_fullname)] = '\0';
	
	address = new char[strlen(_address) + 1];
	for (int i = 0; i < strlen(_address); ++i) 
		address[i] = _address[i]; 
	address[strlen(_address)] = '\0';

	gpa = _gpa;
	std::cout << "Student::Student(full param) parameterized constructor\n";
}

/**
* @brief Parameterized constructor
* @param s display of student's info as a string
**/
Student::Student(std::string s) {	
	std::stringstream buffer(s); 
	buffer >> id;

	std::string bufferName; 
	buffer >> bufferName;
	fullname = new char[(int)bufferName.size() + 1]; 
	for (int i = 0; i < (int)bufferName.size(); ++i) 
		fullname[i] = bufferName[i];
	fullname[(int)bufferName.size()] = '\0';
	
	std::string bufferAddress;
	buffer >> bufferAddress;
	address = new char[(int)bufferAddress.size() + 1];
	for (int i = 0; i < (int)bufferAddress.size(); ++i) 
		address[i] = bufferAddress[i]; 
	address[(int)bufferAddress.size()] = '\0';
 
 	buffer >> gpa;

	std::cout << "Student::Student(string) parameterized constructor\n";
}

/**
* @brief Copy constructor
* @param other the copied Student
* @note perform deep copy
**/
Student::Student(const Student& other) {
	id = other.id; 
	gpa = other.gpa;
	 
	copyCharArr(fullname, other.fullname);
	copyCharArr(address, other.address);

	std::cout << "Student::Student(const Student&) copy constructor\n";
}

/**
* @brief Move constructor
* @param other the copied Student (temporary)
* @note This constructor has no exception
**/
Student::Student(Student&& other) noexcept {
	id = std::exchange(other.id, 0);
	gpa = std::exchange(other.gpa, 0.0); 
	fullname = other.fullname;
	other.fullname = nullptr;
	address = other.address;
	other.address = nullptr;
	std::cout << "Student::Student(Student&&) move constructor\n";
}

/**
* @brief Destructor
* @note delete fullname and address
**/
Student::~Student() {
	delete []fullname;
	delete []address;
}

/**
* @brief Create a clone of current Student
* @param other Studen to clone
* @return a new Student with same info
* @note Perform deep copy
**/
Student Student::clone() {
	return Student(*this);
}

/**
* @brief set id
* @param newID new id of student
**/
void Student::setID(int newID) {
	id = newID;
}

/**
* @brief get id
**/
int Student::getID() {
	return id;
}

/**
* @brief set fullname
* @param newFullName new full name of student
**/
void Student::setFullName(const char* newFullName) {
	copyCharArr(fullname, newFullName);
}

/**
* @brief get full name
**/
char* Student::getFullName() { return fullname; }


/**
* @brief set address
* @param newAddress update address of student
**/
void Student::setAddress(const char* newAddress) { copyCharArr(address, newAddress); }

/**
* @brief get address
**/
char* Student::getAddress() { return address; }

/**
* @brief set gpa
* @param newGPA update gpa of student
**/
void Student::setGPA(double newGPA) { gpa = newGPA; }

/**
* @brief get GPA
**/
double Student::getGPA() { return gpa; }

/**
* @brief return a string-info student
**/
std::string Student::toString() {
	std::string ret = "";
	std::stringstream buffer;
	buffer << id; 
	ret += buffer.str(); 

	std::string fullNameStr = "";
	for (int i = 0; i < strlen(fullname); ++i) fullNameStr += fullname[i];
	ret += " " + fullNameStr; 

	std::string addressStr = "";
	for (int i = 0; i < strlen(address); ++i) addressStr += address[i]; 
	ret += " " + addressStr; 

	buffer.str(std::string());
	buffer << gpa; 
	ret += " " + buffer.str(); 
	return ret;
}

/**
* @brief print all data
**/
void Student::output() {
	char emp[] = "empty";
	std::cout << id << " " << (fullname == nullptr ? emp : fullname) << " " << (address == nullptr ? emp : address) << " " << gpa << '\n';
}

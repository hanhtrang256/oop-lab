#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <algorithm>
#include <string>

class Student {
private:
	int id;
	char* fullname;
	char* address;
	double gpa;
	
	/**
	* @brief a convenient function to copy array b to a 
	* @note handle the '\0' at end
	* @note make sure the b parameter is correct-format char array and has the '\0'
	* before pass it
	**/
	void copyCharArr(char*& a, const char* b); 
public:
	/**
	* @brief Default constructor
	* @param no parameter, all set to 0 or nullptr
	**/
	Student(); 

	/**
	* @brief Parameterized constructor
	* @param _id student id 
	* @param _fullname fullname of student
	* @param _address student's address
	* @param _gpa student's gpa
	**/
	Student(int _id, const char* _fullname, const char* _address, double _gpa);

	/**
	* @brief Parameterized constructor
	* @param s display of student's info as a string
	**/
	Student(std::string s);

	/**
	* @brief Copy constructor
	* @param other the copied Student
	**/
	Student(const Student& other);

	/**
	* @brief Move constructor
	* @param other the copied Student (temporary)
	* @note This constructor has no exception
	**/
	Student(Student&& other) noexcept;

	/**
	* @brief Destructor
	* @note delete fullname and address
	**/
	~Student(); 

	/**
	* @brief Create a clone of current Student
	* @param other Studen to clone
	* @return a new Student with same info
	* @note Perform deep copy
	**/
	Student clone(); 

	/**
	* @brief set id
	* @param newID new id of student
	**/
	void setID(int newID);
	
	/**
	* @brief get id
	**/
	int getID(); 

	/**
	* @brief set fullname
	* @param newFullName new full name of student
	**/
	void setFullName(const char* newFullName);
	
	/**
	* @brief get full name
	**/
	char* getFullName();


	/**
	* @brief set address
	* @param newAddress update address of student
	**/
	void setAddress(const char* newAddress);
	
	/**
	* @brief get address
	**/
	char* getAddress();

	/**
	* @brief set gpa
	* @param newGPA update gpa of student
	**/
	void setGPA(double newGPA);
	
	/**
	* @brief get GPA
	**/
	double getGPA(); 

	/**
	* @brief return a string-info student
	**/
	std::string toString();

	/**
	* @brief print all data
	**/
	void output();
};

#endif // _STUDENT_H_

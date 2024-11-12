#include "myIntArray.h"
#include <iostream>
#include <algorithm>
#include <string>

int main() {
	// Using dynamic allocated array
	myIntArray m1;
	myIntArray m2;
	
	myIntArray m3;
	myIntArray m4;
	myIntArray m5;

	m1.input();
	m2.input();
	m3.input();
	m4.input();
	m5.input();

	m5=m2;

	std::cin>>m2;
	std::cout<<m2;

	std::cout<<m3[3]<<'\n';
	m3[4]=1;

	std::cout<<(int)m4<<'\n'; // return the size of array
  	return 0;
}

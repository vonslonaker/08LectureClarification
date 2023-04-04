//*********************************************************************
// File name:	 main.cpp
// Author:		 Computer Science, Pacific University
// Date:		   4/4/2023
// Class:		   CS 250
// Assignment: N/A
// Purpose:		 Clarify lecture 8 examples
//*********************************************************************

#include <iostream>
#include <vector> 

using namespace std;

void square3(int* pNum) {
	*pNum *= *pNum; // square value pNum points to 
}

int main() {

	cout << "*** Simple pointer example ***" << endl; 
	int* pX, x;
	x = 8;
	pX = &x; // set pX to point to the addresss of x

	cout << "x is: " << x << endl;
	cout << "x is: " << *pX << endl; //dereference pointer
	cout << "Address of x is: " << &x << endl;
	cout << "Address of x is: " << pX << endl;

	// Note: The following does not work:
	// int *pX = 8;  
	// What variable is the pointer pointing to? 
	// You must make that connection 

	// Pointers as function arguments

	square3(pX);

	cout << "x squared is: " << x << endl;
	cout << "x squared is: " << *pX << endl;

	cout << "\n*** Dynamic memory allocation ***" << endl; 

	int* pInt;
	pInt = new int;  // new returns a pointer to the allocated memory
	*pInt = 5;

	cout << "New int is: " << *pInt << endl;
	cout << "Address of new int is: " << pInt << endl;


	cout << "\n*** Null pointer ***" << endl;

	// Reuse the pointer!

	// Initialize pointers at nullptr to verify memory was allocated

  pInt = nullptr;

	// The following  will change pInt to point to a new int
	// Without this, the following if conditional will fail
	pInt = new int; 

	if (nullptr == pInt) {
		cout << "Memory not allocated\n";
		exit(EXIT_FAILURE);  
	}

  // We now know memory was allocated, so can use the pointer

	*pInt = 10;

	cout << "The new int is: " << *pInt << endl;
	delete pInt; // Use delete since created with new! 
  
	cout << "\n*** Iterators over vectors  ***" << endl;

	vector <int> vec{ 0, 1, 2, 3, 4 };

	// can loop using underlying array structure
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;

	// can loop using a user-defined iterator (i.e. a pointer) 
	// can also use it < end(vec) as loop conditional

	vector<int>::iterator it; 

	for (it = begin(vec); it != end(vec); it++) {
		cout << *it << " "; 
	}
	cout << endl; 

  // can loop using a range-based loop WITHOUT using pointers
	// 
  // Method 1: As we have done previously (not preferred)

	for (int it : vec) {
		cout << it << " ";
	}
	cout << endl;

	// Method 2: Using the auto method (preferred) as is independent
	//					 of datatype

	for (auto it : vec) {
		cout << it << " ";
	}
	cout << endl;

	return EXIT_SUCCESS;
}
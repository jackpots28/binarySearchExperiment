
#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// binarysearch that allows for other data types
template <class genType>
struct searchFunctions{
	static genType genBinSrch(vector<genType>gVec, int leftVec, int rightVec, genType Srch) {
		if (rightVec >= 1) {
			int middle = (leftVec + rightVec) / 2;

			if (gVec.at(middle) == Srch) {
				return middle;
			}
			if (gVec.at(middle) > Srch) {
				return genBinSrch(gVec, leftVec, middle - 1, Srch);
			}
			return genBinSrch(gVec, middle + 1, rightVec, Srch);
		}
		return -1;
	}
}; 


// binarysearch function using only integers
long binarySearch(vector<long>vec, int lVec, int rVec, long searchFor) {
	if (rVec >= 1) {
		int middle = (lVec + rVec) / 2;

		if (vec.at(middle) == searchFor) {
			return middle;
		}
		if (vec.at(middle) > searchFor) {
			return binarySearch(vec, lVec, middle - 1, searchFor);
		}
		return binarySearch(vec, middle + 1, rVec, searchFor);
	}
	return -1;
}


int main() {
	srand(time(NULL));
	long counter = 0;
	bool flag = true;

	vector<long>testVecInt;
	// vector<char>testCharVec;

	// fills vector with random #'s between 0 -> 200000
	for (int i = 0; i <= 100; i++) {
		testVecInt.push_back(rand() % 10 + 1);
	}
	sort(testVecInt.begin(), testVecInt.end());
	
	for (int x = 0; x < testVecInt.size(); x++) {
		cout << testVecInt.at(x) << " ";
	}
	cout << endl;
	/*
	// fills vector with chars from a to z
	for (char j = 'a'; j <= 'z'; j++) {
		testCharVec.push_back(j);
	}
	*/

	int resultInt = 0;
	// int resultChar = 0;

	int searchedValInt;
	// char searchChar;

	cout << "Enter an integer to search for: ";
	cin >> searchedValInt;

	/*
	cout << "Enter a character to search for: ";
	cin >> searchChar;
	cout << endl;
	*/

	int sizeOfIntVec = testVecInt.size();
	// int sizeOfCharVec = testCharVec.size();
	
	
	// Does count the full amount when last index value is searched for, but
	// has an out of memory error thrown at the end
	while(flag){
		resultInt = binarySearch(testVecInt, 0, sizeOfIntVec, searchedValInt);

		if (resultInt != -1) {
		
			counter++;
			testVecInt.at(resultInt) = -1;
			sort(testVecInt.begin(), testVecInt.end());
			/*
			for (int i = 0; i < testVecInt.size(); ++i) {
				cout << testVecInt.at(i) << " ";
			}
			*/
			cout << endl;
			cout << counter << endl;
		}
		else if (resultInt == -1) {
			flag = false;
		}
		
	}

	// cout << "The vector contains: " << counter << " instances of number: " << searchedValInt << endl;

	/*
	if (resultInt == -1) {
		cout << "Value not found in vector." << endl;
	}
	else 
		cout << "Value found at index: " << resultInt << endl;
	
	
	// Implemented a template class type so that it could be used to search vectors
	// of other data types
	resultChar = searchFunctions<char>::genBinSrch(testCharVec, 0, sizeOfCharVec, searchChar);
		
	if (resultChar == -1) {
		cout << "Value not found in vector of chars."
			<< endl;
	}
	else
		cout << "Value found at index: " << resultChar << endl;
	*/

    return 0;
}



#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//binarysearch that allows for other data types
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


//binarysearch function using only integers
int binarySearch(vector<int>vec, int lVec, int rVec, int searchFor) {
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
	vector<int>testVecInt;
	vector<char>testCharVec;

	for (int i = 0; i <= 20; i++) {
		testVecInt.push_back(i);
	}

	for (char j = 'a'; j <= 's'; j++) {
		testCharVec.push_back(j -1);
	}

	int resultInt = 0;
	int resultChar = 0;

	int searchedValInt;
	char searchChar;

	cout << "Enter an integer to search for: ";
	cin >> searchedValInt;

	cout << "Enter a character to search for: ";
	cin >> searchChar;

	cout << endl;

	int sizeOfIntVec = testVecInt.size();
	int sizeOfCharVec = testCharVec.size();
	

	//Binary search using just a vector of integers
	resultInt = binarySearch(testVecInt, 0, sizeOfIntVec, searchedValInt);
		
	if (resultInt == -1) {
		cout << "Value not found in vector." << endl;
	}
	else 
		cout << "Value found at index: " << resultInt << endl;
	
	
	//Implemented a template class type so that it could be used to search vectors
	//of other data types
	resultChar = searchFunctions<char>::genBinSrch(testCharVec, 0, sizeOfCharVec -1, searchChar);
		
	if (resultChar == -1) {
		cout << "Value not found in vector of chars."
			<< endl;
	}
	else
		cout << "Value found at index: " << resultChar << endl;


    return 0;
}


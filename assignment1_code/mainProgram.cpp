#include "testing.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
// TO DO 
// add necessary include for your library
#include "myLibrary.h"


using namespace std;


int main () {
	// testCase data structure is defined in testing.h
	vector<testCase> testCases;

	/* test cases are defined in the file testFileName
	The file is expected to have to following formatting: 
	<Number of tests>
	<list of numbers with value separated with spaces> e.g. 1 2 3 3 4
	<value> e.g. 3
	<expected after moving all occurrences  of value> e.g. 1 2 4 3 3
	<Number of elements not equal to value> e.g. 3
	-- REPEAT -- for as many test cases as <Number of tests>
	*/
	string testFileName = "test_cases.txt";

	if (readTestCases(testFileName, testCases)){
		
		for (int i = 0; i < testCases.size(); i++){
			testCase tc = testCases[i];

			// test your function
			bool funcTestList = true; 

			// ---------- This is a call to the function you will implement --
			int nonValueElements = removeValue(tc.inputNumbers, tc.value);
			// ---------------------------------------------------------------

			bool funcTestNum = (nonValueElements == tc.expectedNum);

			// Sort the first k elements
			std::sort(tc.inputNumbers.begin(), tc.inputNumbers.begin() + nonValueElements);
			std::sort(tc.expectedNumbers.begin(), tc.expectedNumbers.begin() + nonValueElements);
			
			// for (int i = 0; i < nonValueElements; i++) {
			for (int i = 0; i < tc.expectedNumbers.size(); i++) {
				if (tc.inputNumbers[i] != tc.expectedNumbers[i]){
					funcTestList = false; 
					break;
				}
			}

			// Diplay results
			cout << "-------------- Testcase " << i+1 << endl;
			cout << "removeValue -- number " << (funcTestNum ? "PASSED" : "* FAILED *") << endl;
			cout << "removeValue -- list   " << (funcTestList ? "PASSED" : "* FAILED *") << endl;
		}

	}else{
		cout << "Testing file was not found!" << endl ;
	}
	return 0;
}
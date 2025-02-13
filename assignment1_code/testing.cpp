#include "testing.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void processNumbers (istringstream& iss, string line, vector<int>& numbers){
	iss.clear();
	iss.str(line);
	int number;

	while (iss >> number) {
		numbers.push_back(number);
	}

}

bool readTestCases(string fileName, vector<testCase>& testCases){
	string nextLine;
	ifstream testFile (fileName);
	
	if (testFile.is_open()){
		int numberTests;
		getline (testFile, nextLine);
		istringstream iss(nextLine);
		iss >> numberTests;

		for (int test = 1; test <= numberTests; test ++){
			// all varibales will be initialized with values from file
			testCase tcase;

			// read the list of input numbers
			getline(testFile, nextLine);
			processNumbers(iss, nextLine, tcase.inputNumbers);

			
			// read value in the next line
			getline(testFile, nextLine);
			iss.clear();
			iss.str(nextLine);
			iss >> tcase.value;

			// read the list of expected numbers
			getline(testFile, nextLine);
			processNumbers(iss, nextLine, tcase.expectedNumbers);

			// read expected number elements not equal to value 
			getline(testFile, nextLine);
			iss.clear();
			iss.str(nextLine);
			iss >> tcase.expectedNum;

			// add new test case to the list 
			testCases.push_back(tcase);


		}
		
		// close file reader
		testFile.close();
		return true;

	}else{
		return false;
	}
}
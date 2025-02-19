#include <iostream>
#include <fstream>
#include "myLibrary.h"
#include "testing.cpp"
 
int removeValue(std::vector<int>& numbers, int value) {
int numOccurrences = 0; //To keep track of each occurrence of value
int lastIndex = numbers.size() - 1;

for (int currentIndex = 0; currentIndex < lastIndex || currentIndex <= lastIndex - numOccurrences ; currentIndex++) { //If no value is found, loop exits once it has been fully iterated through
    if (numbers[currentIndex] == value) {//Swapping current index of iteration (where value is found), with last position of vector to sort numbers in-place
        numbers[currentIndex] = numbers[lastIndex - numOccurrences];
        numbers[lastIndex - numOccurrences] = value;
        numOccurrences++;
    }
}

return numbers.size() - numOccurrences; //returns an integer equal to number of elements not equal to value in the passed in vector
 }



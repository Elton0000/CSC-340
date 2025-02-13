#include <iostream>
#include <fstream>
#include "myLibrary.h"

int main () {
myLibrary newLibrary;
newLibrary.numbers = {5, 2 , 2 , 1 , 2 , 4};
for (int num : newLibrary.numbers) {
std::cout << num << " ";
}
return 0;
}
    int removeValue(int x, int y) {
    x = y;
    return 0;
    }
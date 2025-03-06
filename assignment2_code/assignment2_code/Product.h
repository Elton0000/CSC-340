#ifndef Product_h
#define Product_h
// TO DO: #include all the standard libraries and your own libraries here
#include <iostream>
// To DO: define the class Product with the necessary functions' prototypes and data fields

class Product {
private:
    std::string name;
    std::string description;
    double rating = 0;
    int sellCount = 0;
public:
    Product();
    Product(std::string name, std::string description, double rating, int sellCount);
    
    std::string getName();
    std::string getDescription();
    double getRating();
    int getSellCount();

    void setName(std::string name);
    void setDescription(std::string description);
    virtual void setInfo();
    virtual bool repeatInfo();
// This is a function that allows you to compare two products based on their name. 
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator overloading function prototype:
bool operator==(const Product& otherProduct) const; 
};
#endif
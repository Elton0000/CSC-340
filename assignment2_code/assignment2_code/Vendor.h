#ifndef Vendor_h
#define Vendor_h
// TO DO: #include all the standard libraries and your own libraries here
#include <iostream>
#include "LinkedBag.h"
#include "Product.h"
// To DO: define the class Vendor with the necessary functions and data fields
class Vendor {
    public:
        std::string username;
        std::string email;
        std::string password;
        std::string bio;
        std::string profilePic;
        LinkedBag <Product<int>> productList;

    public:
        //bool operator==(const Vendor& otherVendor) const;
        void displayVendorMenu(Vendor& vendor);
        std::string getUsername(); 

// This is a function that allows you to compare two vendors based on their username and email address.  
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator == overloading function prototype:
bool operator==(const Vendor& otherVendor) const; 
};
#endif
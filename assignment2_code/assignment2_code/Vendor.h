#ifndef Vendor_h
#define Vendor_h
// TO DO: #include all the standard libraries and your own libraries here
#include "LinkedBagDS/LinkedBag.h"
#include "Product.h"

// To DO: define the class Vendor with the necessary functions and data fields
class Vendor {
    private:
        std::string username;
        std::string email;
        std::string password;
        std::string bio;
        std::string profilePic;
        LinkedBag<Product*> productList; 
        
    public:
        Vendor ();
        Vendor(std::string username, std::string email, std::string password, std::string bio, std::string profilePic);
        void displayVendorMenu(Vendor& vendor);
        void displayInfo();
    private:
        void modPassword();
    public:
        void createProd();
        void displayAllProd();
        void displayProd(int index);
        void modProd(Product& productToMod);
        void sellProd(int index, int howMany);
        void deleteProd(); //asked by client to implement

        void changePasswordCheck();
        void setupProfile();
        std::string getUsername() const;
        std::string getEmail() const;
        std::string getPassword() const;
        std::string getBio() const;
        std::string getProfilePicDirectory() const;
        LinkedBag<Product*> getProductList() const;

        void setUsername(std::string username);
        void setEmail(std::string email);
        void setPassword(std::string password);
        void setBio(std::string bio);
        void setProfilePicDirectory(std::string directory);

// This is a function that allows you to compare two vendors based on their username and email address.  
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator == overloading function prototype:
bool operator==(const Vendor& otherVendor) const; 
};
#endif
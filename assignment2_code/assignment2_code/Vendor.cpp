// TO DO: #include needed standard libraries and your own libraries here
#include <iostream>
#include <string>
#include "Vendor.h"
#include "LinkedBagDS/LinkedBag.h"
#include "Product.h"
#include "Goods.h"
#include "Media.h"

// TO DO: function implementations
Vendor::Vendor () {

}

Vendor::Vendor(std::string username, std::string email, std::string password, std::string bio, std::string profilePic){
	this->username = username;
	this->email = email;
	this->password = password;
	this->bio = bio;
	this->profilePic = profilePic;
}

void Vendor::displayInfo() {
std::cout << "Username: " << this->getUsername() << "\n";
std::cout << "Email: " << this->getEmail() << "\n";
std::cout << "Bio: " << this->getBio() << "\n";
std::cout << "Profile Picture: " << this->getProfilePicDirectory() << "\n";
}

void Vendor::createProd(){
// TO DO: ask vendor to choose product type, then ask them to input product details.
// Create the product and add it to the vendor's products
	std::cout << "What type of product do you wish to add? (Goods or Media): ";
	std::string type;
	std::cin >> type;
	
	while (type != "Goods" && type != "Media") {
		std::cout << "Invalid product type.\nPlease enter the type of product you wish to add (Goods or Media): ";
		std::cin >> type;
	}
	if (type == "Goods") {
		Goods* goods = new Goods();
		(*goods).setInfo();
		this->productList.add(goods);
	}
	else {
		Media* media = new Media();
		(*media).setInfo();
		this->productList.add(media);
	}
	std::cout << "Would you like to add another item? (y,n): ";
	std::string choice;
	std::cin >> choice;
	if (choice == "y") {
		std::cout << "\n";
		createProd();
	}
}

void Vendor::displayAllProd(){ //idea is to loop through bag and use repeatInfo method on each "Product" item
	//No way to actually access first node, have to convert to a vector first?
	if (this->productList.isEmpty()) {
		std::cout<< "No recorded items. Please add to the display first.\n";
	}
	else {
		std::vector<Product*> display = getProductList().toVector();
		for (int i = 0; i < this->productList.getCurrentSize(); i++) {
		(*display[i]).displayContent();
		}
	}
}

void Vendor::displayProd(){
	displayProductNames();
	std::cout << "Input the index of the item you would like to view (leftmost is index 0): ";
	int index;
	std::cin >> index;
	while (std::cin.fail()) {
		std::cout << "\nInvalid input, please enter a number: ";
		std::cin.clear();
		std::cin.ignore();
		std::cin >> index;
	}
	if (index >= this->productList.getCurrentSize() || index < 0) {
		std::cout << "Index out of bounds. Please try again.\n";
	}
	else {	
		std::vector<Product*> myList = getProductList().toVector();
		(*myList[index]).displayContent();
	}
}

void Vendor::modProd(){
	displayProductNames();
	std::cout << "Input the index of the item you would like to modify (leftmost is index 0): ";
	int index;
	std::cin >> index;
	while (std::cin.fail()) {
		std::cout << "\nInvalid input, please enter a number: ";
		std::cin.clear();
		std::cin.ignore();
		std::cin >> index;
	}

	if (index >= this->productList.getCurrentSize() || index < 0) {
		std::cout << "Index out of bounds. Please try again.\n";
	}

	else {
		
		std::vector<Product*> myList = getProductList().toVector();
		(*myList[index]).setInfo();
	}

}

void Vendor::sellProd(int index, int howMany){
	int rex;
	std::cin >> rex;
	std::cout << (*(this->productList.reverseFindKthItem(rex))).getItem()->getName();
}

void Vendor::deleteProd(){

}
void Vendor::changePasswordCheck() {
	std::cout << "First, please confirm your old password: ";
	std::string oldPassword;
	std::cin.ignore() >> oldPassword;
	int tries = 3;
	while (tries > 0 && oldPassword != (this->getPassword())) {
		std::cout << "Mismatching password input, you have _" << tries << "_ left\n";
		tries--;
		std::cout << "Old Password: ";
		std::cin >> oldPassword;
	}
	if (oldPassword == this->getPassword()) {
		std::cout << "Please enter a new password: ";
		modPassword();
	}
	else {
		std::cout << "Security check failed, logging out...";
		exit(1);
	}
}
void Vendor::setupProfile(){
std::cout << "Please enter your name: ";
std::getline(std::cin,this->username);

std::cout << "Please enter your email: "; 
std::getline(std::cin,this->email);

std::cout << "Please enter a password: "; 
std::getline(std::cin,this->password);

std::cout << "Please tell us a bit about yourself: "; 
std::getline(std::cin,this->bio);

std::cout<<	"Please enter a directory to your image of choice: "; 
std::cin >> this->profilePic;
}

std::string Vendor::getUsername() const {
return this->username;
}

std::string Vendor::getEmail() const {
return this->email;
}

std::string Vendor::getPassword() const {
return this->password;
}

std::string Vendor::getBio() const {
return this->bio;
}

std::string Vendor::getProfilePicDirectory() const {
return this->profilePic;
}

LinkedBag<Product*> Vendor::getProductList() const{
	return productList;
}

void Vendor::setUsername(std::string username){
this->username = username;
}

void Vendor::setEmail(std::string email){
this->email = email;
}

void Vendor::setPassword(std::string password){
this->password = password;
}

void Vendor::setBio(std::string bio){
this->bio = bio;
}

void Vendor::setProfilePicDirectory(std::string directory){
this->profilePic = directory;
}

void Vendor::modPassword(){
	std::string newPassword;
	std::cin >> newPassword;
	this->setPassword(newPassword);
}

void Vendor::displayProductNames(){
	std::vector<Product*> display = getProductList().toVector();
	std::string nameList = "[";
	for (int i = 0; i < this->productList.getCurrentSize(); i++) {
		if (i + 1 == this->productList.getCurrentSize()) {
			nameList += ((*display[i]).getName() + "]");
		}
		else {
			nameList += ((*display[i]).getName() + ", ");
		}
	}
	std::cout << nameList << "\n";
}
// Operator == overloading implementation
bool Vendor::operator==(const Vendor& otherVendor) const {
	return (Vendor::username == otherVendor.username) && (Vendor::email == otherVendor.email);
}

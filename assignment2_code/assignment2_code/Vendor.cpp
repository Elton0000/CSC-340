// TO DO: #include needed standard libraries and your own libraries here
#include <iostream>
#include <string>
#include "Vendor.h"
#include "LinkedBagDS/LinkedBag.h"
#include "Product.h"
#include "Goods.h"
#include "Media.h"
#include <memory>
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

// Vendor::Vendor(const Vendor& vendor) {
// // 	: username(vendor.username),
// // 	  email(vendor.email),
// // 	  password(vendor.password),
// // 	  bio(vendor.bio),
// // 	  profilePic(vendor.profilePic)


// }

//copy constructor
Vendor& Vendor::operator=(const Vendor& rhs) {
	this->username = rhs.getUsername();
	this->password = rhs.getPassword();
	this->email = rhs.getEmail();
	this->bio = rhs.getBio();
	this->profilePic = rhs.getProfilePicDirectory();
	return *this;
}

void Vendor::displayInfo() {
std::cout << (*this);

// std::cout << "Username: " << this->getUsername() << "\n";
// std::cout << "Email: " << this->getEmail() << "\n";
// std::cout << "Bio: " << this->getBio() << "\n";
// std::cout << "Profile Picture: " << this->getProfilePicDirectory() << "\n";
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
		
		
		std::shared_ptr<Goods> goodsPtr = std::make_shared<Goods>();
		goodsPtr -> setInfo();
		productList.add(goodsPtr);
	
		// Goods* goodsPtr = new Goods();
		// (*goodsPtr).setInfo();
		// this->productList.add(goodsPtr);
	}
	else {

		std::shared_ptr<Media> mediaPtr = std::make_shared<Media>();
		mediaPtr -> setInfo();
		productList.add(mediaPtr);
			
		// Media* media = new Media();
		// (*media).setInfo();
		// this->productList.add(mediaPtr);
	}
	
	if (tryAgain(1)) { //exception handling method
		std::cout << "\n";
		createProd();
	}
}

void Vendor::displayAllProd(){ //idea is to loop through bag and use repeatInfo method on each "Product" item
	//No way to actually access first node, have to convert to a vector first?
		std::vector<std::shared_ptr<Product>> display = getProductList().toVector(); 
		for (int i = 0; i < this->productList.getCurrentSize(); i++) {
		(*display[i]).displayContent();
		}
}

void Vendor::displayProd(){
	displayProductNames();
	int index = getIndexChoice(1); //less lines of code, this appears quite a bit
	this->productList.reverseFindKthItem(index)->getItem()->displayContent(); // find the point I want, then display contents
		if (tryAgain(2)) {
			displayProd();
		}
	}

void Vendor::modProd(){
	displayProductNames();
	int index = getIndexChoice(2);
	this->productList.reverseFindKthItem(index)->getItem()->setInfo();
	if (tryAgain(3)) {
			modProd();
	}
}

void Vendor::sellProd(){
	displayProductNames();
	int index = getIndexChoice(3);
	this->productList.reverseFindKthItem(index)->getItem()->sell(); 
	if (tryAgain(4)) {
		sellProd();
	}
}

void Vendor::deleteProd(){
	displayProductNames();
	int index = getIndexChoice(4);
	if (this->productList.remove(this->productList.reverseFindKthItem(index)->getItem())) { //deletes nodes at specified index, frees up memory, relinks nodes
		std::cout << "Successful Removal\n";
	}
	else {
		std::cout << "Unsuccessful Removal.\n";
	}
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

	std :: cin >> (*this);
	
	
	
	// std::cout << "Please enter your name: ";
	// std::getline(std::cin,this->username);

	// std::cout << "Please enter your email: "; 
	// std::getline(std::cin,this->email);

	// std::cout << "Please enter a password: "; 
	// std::getline(std::cin,this->password);

	// std::cout << "Please tell us a bit about yourself: "; 
	// std::getline(std::cin,this->bio);

	// std::cout<<	"Please enter a directory to your image of choice: "; 
	// std::cin >> this->profilePic;
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

LinkedBag<std::shared_ptr<Product>> Vendor::getProductList() const{
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
	std::vector<std::shared_ptr<Product>> display = getProductList().toVector(); // just so i don't need to deal with node class and roundabout way of displaying info
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

bool Vendor::tryAgain(int x) {
	std::string choice;
	switch (x) {
		case 1: {
				std::cout << "Would you like to add another item? (y,n): ";
				break;
			}
		case 2: {
				std::cout << "Would you like to view another item? (y,n): ";
				break;
			}
		case 3: {
				std::cout << "Would you like to modify another item? (y,n): ";
				break;
			}
		case 4: { 
				std::cout << "Would you like to sell another item? (y,n): ";
				break;
			}
		case 5: {
			std::cout << "Would you like to delete another item? (y,n): ";
			break;
			}
		default: {
			std::cout << "Would you like to try another item? (y,n): ";
			break;
			}
	}
	std::cin >> choice;
	return choice == "y";
}

int Vendor::getIndexChoice(int x) {
	int choice;
	switch (x) {
		case 1: {
				std::cout << "Input the index of the item you would like to view (leftmost is index 0): ";
				break;
			}
		case 2: {
				std::cout << "Input the index of the item you would like to modify (leftmost is index 0): ";
				break;
			}
		case 3: {
				std::cout << "Input the index of the item you would like to sell (leftmost is index 0): ";
				break;
			}
		case 4: { 
				std::cout << "Input the index of the item you would like to delete (leftmost is index 0): ";
				break;
			}
		default: {
			break;
			}
	}

	std::cin >> choice;
	while (std::cin.fail() || choice >= this->productList.getCurrentSize() || choice < 0) {
		std::cin.clear();
		std::cin.ignore();
		if (choice >= this->productList.getCurrentSize() || choice < 0) {
			std::cout << "\nInput out of bounds, please enter a valid index: ";
		}
		else {
			std::cout << "\nInvalid input, please enter a number: ";
		}
		std::cin >> choice;
	}
	return choice;
}
// Operator == overloading implementation
bool Vendor::operator==(const Vendor& otherVendor) const {
	return (Vendor::username == otherVendor.username) && (Vendor::email == otherVendor.email);
}

std::ostream& operator<<(std::ostream& out,const Vendor& vendor) { //overloading 
	out << "Username: " << vendor.getUsername() << "\n";
	out << "Email: " << vendor.getEmail() << "\n";
	out << "Bio: " << vendor.getBio() << "\n";
	out << "Profile Picture: " << vendor.getProfilePicDirectory() << "\n";                                        
    return out;
}

std::istream& operator>>(std::istream& in, Vendor& vendor) { //overloading
    std::string answer;
    std::cout << "Please enter your name: ";
	in >> answer;
	vendor.setUsername(answer);

	std::cout << "Please enter your email: "; 
	in >> answer;
	vendor.setEmail(answer);

	std::cout << "Please enter a password: "; 
	in >> answer;
	vendor.setPassword(answer);

	std::cout << "Please tell us a bit about yourself: "; 
	in >> answer;
	vendor.setBio(answer);

	std::cout<<	"Please enter a directory to your image of choice: "; 
	in >> answer;
	vendor.setProfilePicDirectory(answer);

	return in;
    
}
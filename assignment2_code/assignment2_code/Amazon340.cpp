// TO DO: Implementation of Amazon340 functions
#include <iostream>
#include <string>
#include "Amazon340.h"
#include "Vendor.h"
// TO DO: implement constructor
Amazon340::Amazon340(){
	
}
// TO DO: implement destructor
Amazon340::~Amazon340() {
	
}
void Amazon340::createVendor(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture){
	// TO DO: implement function
	vendor.setUsername(username);
	vendor.setEmail(email);
	vendor.setPassword(password);
	vendor.setBio(bio);
	vendor.setProfilePicDirectory(profilePicture);
}
Vendor Amazon340::getVendor() const{
	// TO DO: implement function
	return this->vendor;
}
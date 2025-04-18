#ifndef Amazon340_h
#define Amazon340_h
//#include "LinkedBagDS/LinkedBag.h"
// TO DO include necessary libraries
#include "Vendor.h" 

// This class only contains a vendor
class Amazon340 {
	private:
		Vendor vendor; //call no args Vendor class constructor

	public:
		Amazon340();
		~Amazon340();
		
		void createVendor(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture);
		Vendor getVendor() const;
};
#endif
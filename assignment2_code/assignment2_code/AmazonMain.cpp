#include <iostream> 
#include <string>

// TO DO: #include any other libraries you need
#include "Amazon340.cpp"
#include "Amazon340.h"
#include "Vendor.cpp"
#include "Vendor.h"
#include "Product.cpp"
#include "Product.h"
#include "Goods.cpp"
#include "Goods.h"
#include "Media.cpp"
#include "Media.h"

using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type Vendor
 * @param vendor object to interact with
 * 
 * */
void displayVendorMenu(Vendor& vendor){
	int vendorChoice = 0;
	do {
		cout << "\nHi, "<< vendor.getUsername() <<", what would you like to do:\n"
		<< "1. Display Profile\n"
		<< "2. Modify Password\n"
		<< "3. Create Product\n"
		<< "4. Display All Products\n"
		<< "5. Display Kth Product\n"
		<< "6. Modify Product\n"
		<< "7. Sell Product\n"
		<< "8. Delete Product\n"
		<< "0. Logout\n"
		<< "Choice: ";
		cin >> vendorChoice;
		std::cout << "\n";
		
		switch (vendorChoice) {
			case 1:{
				// TO DO: display vendor's profile information
				//      : e.g. vendor.displayProfile();
				vendor.displayInfo();
				break;
			}
			case 2: {
				// TO DO: ask for new password and update vendor's password
				vendor.changePasswordCheck();
				break;
			}
			case 3: {
				// TO DO: ask vendor to choose product type, then ask them to input product details.
				// Create the product and add it to the vendor's products
				vendor.createProd();
				break;
			}
			case 4:{
				// TO DO: display all vendor's products
				//        You may re-use code from class demo
				if (vendor.getProductList().isEmpty()) {
					std::cout << "You do not have any items to display. Please add some products and try again.\n";
					break;
				}
				vendor.displayAllProd();
				break;
			}
			case 5: {
				// TO DO: ask the vendor for a value k
				// Find the Kth product, if k > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				if (vendor.getProductList().isEmpty()) {
					std::cout << "You do not have any items to display. Please add some products and try again.\n";
					break;
				}
				vendor.displayProd();
				break;
			}
			case 6: {
				// TO DO: ask the vendor for the index of the product they want to modify.
				// Find the product, then prompt them for the new name and description.
				// Modify the product accordingly. 
				// If index > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				if (vendor.getProductList().isEmpty()) {
					std::cout << "You do not have any items to modify. Please add some products and try again.\n";
					break;
				}
				vendor.modProd();	
				break;
			}
			case 7: {
				// TO DO: ask the vendor for the index of the product they want to sell 
				// Find the product, then sell the product. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
				if (vendor.getProductList().isEmpty()) {
					std::cout << "You do not have any items to sell. Please add some products and try again.\n";
					break;
				}
				vendor.sellProd();
				break;
			}
			case 8:{
				// TO DO: ask the vendor for the index of the product they want to delete 
				// Find the product, then remove it from the list. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
				if (vendor.getProductList().isEmpty()) {
					std::cout << "You do not have any items to delete. Please add some products and try again.\n";
					break;
				}
				vendor.deleteProd();
				break;
			}
			case 0: {
				cout << "Logging you out." << endl;
				break;
			}
			default:
				cout << "Invalid choice. Please try again." << endl;
		}

	} while (vendorChoice != 0);
}


int main(){	
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one vendor
	Amazon340 amazon340; 
	
	cout << amazon340 << endl;
	// TO DO: Ask the vendor to enter their information 
	//        Instantiate a new Vendor object
	
	Vendor myVendor;
	myVendor.setupProfile();
	// call amazon340 createVendor function 
	// replace /*...*/ with the right parameters
	
	amazon340.createVendor(myVendor.getUsername(), myVendor.getEmail(), myVendor.getPassword(), myVendor.getBio(), myVendor.getProfilePicDirectory());
	// Retrieve the vendor 
	Vendor currentVendor = amazon340.getVendor();

	// Display the main menu
	displayVendorMenu(currentVendor);
				
	return 0;
}
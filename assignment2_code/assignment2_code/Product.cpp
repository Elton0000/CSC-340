// TO DO: #include all the standard libraries and your own libraries here
#include "Product.h"

// TO DO: function implementations
Product::Product() {

}
Product::Product(std::string name, std::string description, double rating, int sellCount){

}

std::string Product::getName(){
	return this->name;
}

std::string Product::getDescription(){
	return this->description;
}

double Product::getRating(){
	return this->rating;
}

int Product::getSellCount() {
	return this->sellCount;
}
void Product::setName(std::string name) {
	this->name = name;
}
void Product::setDescription(std::string description){
	this->description = description;
}
void Product::setInfo() {

}
bool Product::repeatInfo(){
	return false;
}
// ------------------------------------------------------------------------------
// Operator overloading implementation
bool Product::operator==(const Product& otherProduct) const {
	return Product::name == otherProduct.name;
}





// TO DO: #include all the standard libraries and your own libraries here
#include "Product.h"

// TO DO: function implementations
Product::Product() {

}


Product::Product(std::string name, std::string description, double rating, int sellCount){

}

Product::~Product() {

}

std::string Product::getName() const{
	return this->name;
}

std::string Product::getDescription() const{
	return this->description;
}

double Product::getRating() const{
	return this->rating;
}

int Product::getSellCount() const{
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
void Product::setRating(int amount) {
	this->rating += (amount * 0.02);

	if (this->rating > 5) {
		this->rating = 5;
	}
}

void Product::setSellCount(int amount) {
	this->sellCount += amount;
}

bool Product::repeatInfo(){
	return false;
}

void Product::displayContent() {

}

void Product::sell() {

}
// ------------------------------------------------------------------------------
// Operator overloading implementation
bool Product::operator==(const Product& otherProduct) const {
	return Product::name == otherProduct.name;
}





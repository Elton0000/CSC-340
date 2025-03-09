#include <iostream>
#include <string>
#include "Goods.h"
#include "Product.h"

Goods::Goods() {
    Product();
}
Goods::Goods(std::string name, std::string description, double rating, int sellCount, std::string expirationDate, int quantity) {
    Product(name,description,rating,sellCount);
    this->expirationDate = expirationDate;
    this->quantity = quantity;
}

std::string Goods::getExpirationDate() const{
    return this->expirationDate;
}

int Goods::getQuantity() const{
    return this->quantity;
}

void Goods::setExpirationDate(std::string expirationDate) {
    this->expirationDate = expirationDate;
}

void Goods::setQuantity(int quantity){
    this->quantity = quantity;
}

void Goods::setInfo() {
    bool satisfied = false;
    std::string name;
    std::string description;
    std::string expirationDate;
    int quantity;
    
    while (!satisfied) {
        std::cout << "\nWhat is your goods called?\nName: ";
        std::cin.ignore();
        std::getline(std::cin,name);
        this->setName(name);

        std::cout << "\nPlease give a description of your goods.\nDescription: ";
        std::getline(std::cin,description);
        this->setDescription(description);

        std::cout << "\nPlease tell us the date of expiration for this goods.\nExpiration Date: ";       
        std::getline(std::cin,expirationDate);
        this->setExpirationDate(expirationDate);

        std::cout << "\nPlease list the quantity that will be in stock\nQuantity: ";    
        std::cin >> quantity;
            if (std::cin.fail()) {
                std::cout << "Invalid input for quantity, default amount: 0 is set.\n";
                std::cin.clear();
                std::cin.ignore(); //exception handling
            }
        this->setQuantity(quantity);
        satisfied = repeatInfo();
    }
}

void Goods::displayContent() {
    std::cout << "\nDisplaying info of current goods\nName: " << this->getName()
                                                << "\nDescription: " << this->getDescription()
                                                << "\nRating(increases as items are sold): " << this->getRating()
                                                << "\nSell Count(increases as items are sold): " << this->getSellCount()
                                                << "\nExpiration Date: " << this->getExpirationDate()
                                                << "\nQuantity to be Sold: " << this->getQuantity() << "\n";
}

void Goods::sell() {
    displayContent();
    std::cout << "\nHow many units would you like to sell [" << getQuantity() << "]: ";
    int sellAmount;
    std::cin >> sellAmount;
    while (std::cin.fail() || sellAmount > getQuantity()) {
        std::cin.clear();
        std::cin.ignore();
        if (sellAmount > getQuantity()) {
            std::cout << "Only " << getQuantity() << " available, please select a smaller number: ";
        }
        else {
            std::cout << "Invalid input, please try again: "; 
        } //exception handling
        std::cin >> sellAmount;
    }
    setQuantity(getQuantity() - sellAmount);
    setRating(sellAmount);
    setSellCount(sellAmount);//adjusting rating and sell count as items are sold
    std::cout << "Sale completed!\n\n";
}

bool Goods::repeatInfo(){
    bool satisfaction = false;
    std::cout << "\nDisplaying info of current goods\nName: " << this->getName()
                                                << "\nDescription: " << this->getDescription()
                                                << "\nRating(increases as items are sold): " << this->getRating()
                                                << "\nSell Count(increases as items are sold): " << this->getSellCount()
                                                << "\nExpiration Date: " << this->getExpirationDate()
                                                << "\nQuantity to be Sold: " << this->getQuantity()
                                                << "\nIs this all correct? (y,n): ";
    std::string answer;
    std::cin >> answer;

    if (answer == "y") {
        satisfaction = true; 
    }
    else {
        satisfaction = false;
    }  
                                            
return satisfaction;
}

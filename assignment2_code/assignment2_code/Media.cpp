#include <iostream>
#include <string>
#include "Media.h"
#include "Product.h"

Media::Media() {
    Product();
}

Media::Media (std::string name, std::string description, double rating, int sellCount, std::string type, std::string targetAudience) {
    Product(name,description,rating,sellCount);
    this->type = type;
    this->targetAudience = targetAudience;
}

Media::Media(const Media& media) {
	std::shared_ptr myMedia = std::make_shared<Media>();
	*myMedia = media;
}

Media::~Media() {

}

std::string Media::getType() const {
    return this->type;
}

std::string Media::getTargetAudience() const {
    return this->targetAudience;
}

void Media::setType(std::string type) {
    this->type = type;
}

void Media::setTargetAudience(std::string target){
    this->targetAudience = target;
}

void Media::setInfo() {
    bool satisfied = false;
    std::string name;
    std::string description;
    std::string type;
    std::string targetAudience;
    
    while (!satisfied) {
        std::cout << "\nWhat is your media called?\nName: ";
        std::cin.ignore();
        std::getline(std::cin,name);
        this->setName(name);

        std::cout << "\nPlease give a description of your media.\nDescription: ";
        std::getline(std::cin,description);
        this->setDescription(description);

        std::cout << "\nPlease describe what type of media this is.\nType: ";       
        std::getline(std::cin,type);
        this->setType(type);

        std::cout << "\nPlease describe who the intended audience for this media is.\nTarget Audience: ";    
        std::getline(std::cin,targetAudience);
        this->setTargetAudience(targetAudience);

        satisfied = repeatInfo();
    }
}

void Media::displayContent() {
    std::cout << (*this);
    
    // std::cout << "\nDisplaying info of current Media\nName: " << this->getName()
    //                                             << "\nDescription: " << this->getDescription()
    //                                             << "\nRating(increases as items are sold): " << this->getRating()
    //                                             << "\nSell Count(increases as items are sold): " << this->getSellCount()
    //                                             << "\nType: " << this->getType()
    //                                             << "\nTarget Audience: " << this->getTargetAudience() << "\n";
}
void Media::sell() {
    displayContent();
    std::cout << "\nPlease provide an access code to complete the sale: ";
    std::string accessCode;
    std::cin >> accessCode;
    
    setRating(1);
    setSellCount(1);
    std::cout << "Sale completed!\n\n";
}

bool Media::repeatInfo(){
    bool satisfaction = false;
    std::string tempName = (*this).getName();
    
    std::cout << (*this);
    std::cin >> (*this);
    
    if ((*this).getName() == "y") {
        (*this).setName(tempName);
        satisfaction = true;
    }
    // std::cout << "\nDisplaying info of current goods\nName: " << this->getName()
    //                                             << "\nDescription: " << this->getDescription()
    //                                             << "\nRating(increases as items are sold): " << this->getRating()
    //                                             << "\nSell Count(increases as items are sold): " << this->getSellCount()
    //                                             << "\nType: " << this->getType()
    //                                             << "\nTarget Audience: " << this->getTargetAudience()
    //                                             << "\nIs this all correct? (y,n): ";
    // std::string answer;
    // std::cin >> answer;
    
    // if (answer == "y") {
    //     satisfaction = true; 
    // }
    // else {
    //     satisfaction = false;
    // }  
                                            
return satisfaction;
}
std::ostream& operator<<(std::ostream& out,const Media& media) { //overloading 
    out << "\nDisplaying info of current goods\nName: " << media.getName()
                                                << "\nDescription: " << media.getDescription()
                                                << "\nRating(increases as items are sold): " << media.getRating()
                                                << "\nSell Count(increases as items are sold): " << media.getSellCount()
                                                << "\nType: " << media.getType()
                                                << "\nTarget Audience: " << media.getTargetAudience();                   
    return out;
}

std::istream& operator>>(std::istream& in, Media& media) { //overloading
    std::string answer;
    std :: cout << "\nIs this all correct (y, n):  ";
    in >> answer;
    media.setName(answer);
    return in;
    
}
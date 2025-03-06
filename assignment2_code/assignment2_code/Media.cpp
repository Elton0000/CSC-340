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

std::string Media::getType(){
    return this->type;
}

std::string Media::getTargetAudience(){
    return this->targetAudience;
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

void Media::setType(std::string type) {
this->type = type;
}

void Media::setTargetAudience(std::string target){
this->targetAudience = target;
}

bool Media::repeatInfo(){
    bool satisfaction = false;
    std::cout << "\nDisplaying info of current goods\nName: " << this->getName()
                                                << "\nDescription: " << this->getDescription()
                                                << "\nRating(increases as items are sold): " << this->getRating()
                                                << "\nSell Count(increases as items are sold): " << this->getSellCount()
                                                << "\nType: " << this->getType()
                                                << "\nTarget Audience: " << this->getTargetAudience()
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
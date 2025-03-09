#include <iostream>
#include "Product.h"
#ifndef Media_h
#define Media_h

class Media : public Product {
private:
    std::string type;
    std::string targetAudience;
    bool repeatInfo() override;
public:
    Media(); //access code for media to be printed as item is sold, instead of every media having same code
    Media(std::string name, std::string description, double rating, int sellCount, std::string type, std::string targetAudience);
    
    std::string getType();
    std::string getTargetAudience();
     

    void setInfo() override;
    void setType(std::string type);
    void setTargetAudience(std::string targetAudience);
    void displayContent() override;
};

#endif
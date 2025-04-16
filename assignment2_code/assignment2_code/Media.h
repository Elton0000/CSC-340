#include <iostream>
#include "Product.h"
#ifndef Media_h
#define Media_h

class Media : public Product {
private:
    std::string type;
    std::string targetAudience;
public:
    Media(); //access code for media to be printed as item is sold, instead of every media having same code
    Media(std::string name, std::string description, double rating, int sellCount, std::string type, std::string targetAudience);
    Media(const Media& media) ;
    ~Media();
    
    std::string getType() const;
    std::string getTargetAudience() const;
    void setType(std::string type);
    void setTargetAudience(std::string targetAudience); 

    void setInfo() override;
    void displayContent() override;
    void sell() override; //Polymorphism

    friend std::ostream& operator<<(std::ostream& oS, const Media& media);
    friend std::istream& operator>>(std::istream& iS, Media& media);
    
private:
    bool repeatInfo() override;
};

#endif
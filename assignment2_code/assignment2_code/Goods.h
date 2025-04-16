#include <iostream>
#include "Product.h"
#ifndef Goods_h
#define Goods_h

class Goods : public Product {
private:
    std::string expirationDate;
    int quantity;
    
public:
    Goods();
    Goods(std::string name, std::string description, double rating, int sellCount, std::string expirationDate, int quantity);
    Goods(const Goods& goods);
    ~Goods();
    std::string getExpirationDate() const;
    int getQuantity() const;
    void setExpirationDate(std::string expirationDate);
    void setQuantity(int quantity);

    void setInfo() override;
    void displayContent() override;
    void sell() override; //Polymorphism

    friend std::ostream& operator<<(std::ostream& oS, const Goods& goods);
    friend std::istream& operator>>(std::istream& iS, Goods& goods);
    
private:
    bool repeatInfo() override;
};

#endif
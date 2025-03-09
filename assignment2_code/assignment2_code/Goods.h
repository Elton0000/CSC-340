#include <iostream>
#include "Product.h"
#ifndef Goods_h
#define Goods_h

class Goods : public Product {
private:
    std::string expirationDate;
    int quantity;
    bool repeatInfo() override;
public:
    Goods();
    Goods(std::string name, std::string description, double rating, int sellCount, std::string expirationDate, int quantity);
    std::string getExpirationDate();
    int getQuantity();
    void setInfo() override;
    void setExpirationDate(std::string expirationDate);
    void setQuantity(int quantity);
    void displayContent() override;
};

#endif
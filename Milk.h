#ifndef ASSIGNMENT4_MILK_H
#define ASSIGNMENT4_MILK_H
#include "Product.h"

class Milk: public Product{
public:
    // setting Milk's price to 3
    Milk():Product(){price=3;};
    //Implementation of pure virtual method
    virtual int get_price()const{return price;};
    virtual ~Milk();
};


#endif //ASSIGNMENT4_MILK_H

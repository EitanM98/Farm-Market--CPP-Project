
#ifndef ASSIGNMENT4_WOOL_H
#define ASSIGNMENT4_WOOL_H
#include "Product.h"

class Wool: public Product{
public:
    //setting Wool's price to 2
    Wool():Product(){price=2;};
    //Implementation of pure virtual method
    virtual int get_price()const{return price;};
    virtual ~Wool();
};


#endif //ASSIGNMENT4_WOOL_H

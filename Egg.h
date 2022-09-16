
#ifndef ASSIGNMENT4_EGG_H
#define ASSIGNMENT4_EGG_H
#include "Product.h"

class Egg: public Product{
public:
    //Setting Egg's price to 1
    Egg():Product(){price=1;};
    //Implementation of pure virtual method
    virtual int get_price()const{return price;};
    virtual ~Egg();
};


#endif //ASSIGNMENT4_EGG_H

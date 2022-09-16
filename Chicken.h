
#ifndef ASSIGNMENT4_CHICKEN_H
#define ASSIGNMENT4_CHICKEN_H
#include "Animal.h"

class Chicken : public Animal
{
private:
    static int static_price;
public:
    //Setting price and final age to 3
    Chicken():Animal(){final_age=3,price=3;};
    //getter for static price, without the need of existence of a Chicken object
    static int get_static_price();
    //Implementation of pure virtual methods
    virtual int get_age()const{return age;};
    virtual int get_price()const{return price;};
    virtual int get_final_age()const{return final_age;};
    virtual ~Chicken();
};

#endif //ASSIGNMENT4_CHICKEN_H

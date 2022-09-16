
#ifndef ASSIGNMENT4_SHEEP_H
#define ASSIGNMENT4_SHEEP_H
#include "Animal.h"

class Sheep : public Animal
{
private:
    static int static_price;
public:
    Sheep():Animal(){final_age=5,price=5;};
    //getter for static price, without the need of existence of a Sheep object
    static int get_static_price();
    //Implementation of pure virtual method
    virtual int get_age()const{return age;};
    virtual int get_price()const{return price;};
    virtual int get_final_age()const{return final_age;};
    virtual ~Sheep();
};


#endif //ASSIGNMENT4_SHEEP_H


#ifndef ASSIGNMENT4_COW_H
#define ASSIGNMENT4_COW_H
#include "Animal.h"

class Cow: public Animal
        {
private:
        static int static_price;
    public:
    Cow():Animal(){final_age=10,price=10;};
    //getter for static price, without the need of existence of a Cow object
    static int get_static_price();
    //Implementation of pure virtual method
    virtual int get_age()const{return age;};
    virtual int get_price()const{return price;};
    virtual int get_final_age()const{return final_age;};
    virtual ~Cow();
};


#endif //ASSIGNMENT4_COW_H

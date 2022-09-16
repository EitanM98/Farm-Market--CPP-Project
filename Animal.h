
#ifndef ASSIGNMENT4_ANIMAL_H
#define ASSIGNMENT4_ANIMAL_H
#include <iostream>
#include <cstdio>
#include "Product.h"

using namespace std;

class Animal {
protected:
    int age;
    int price;
    int final_age;
public:
    Animal();
    //copy constructor
    Animal& operator=(const Animal& source);
    //getter methods, pure virtual methods needs to implemented by a specific Animal
    virtual int get_age()const=0;
    virtual int get_price()const=0;
    virtual int get_final_age()const=0;
    // returns true if the Animal has reached its max age, and false otherwise
    bool is_too_old()const;
    // Increases Animal's age by one year
    void addYear();
    virtual ~Animal();
};


#endif //ASSIGNMENT4_ANIMAL_H

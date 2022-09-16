
#ifndef ASSIGNMENT4_FARM_H
#define ASSIGNMENT4_FARM_H
#include <iostream>
#include <vector>
#include "Animal.h"
#include "Product.h"
#include "Milk.h"
#include "Wool.h"
#include "Egg.h"
#include "Cow.h"
#include "Chicken.h"
#include "Sheep.h"

using namespace std;

class Farm {
protected:
    int ID;
    int Money;
    vector<Animal *> animals;
    Product* products[3];
    // Vector of all observers, potential buyers
    vector<Farm *> pot_buyers;
    //static var to give each farm a unique ID
    static int farm_num;
public:
    Farm();
    //Getter methods
    int get_Balance()const;
    int get_ID()const;
    Product** get_products();
    // Increase and decrease method for Farm's Money
    void deposit_Money(int deposit);
    void withdraw_Money(int withdraw);
    // The method Increases each animal of the farm age by 1, and deletes it if it reached its final age
    void updateAnimals();
    virtual void buy_Products(Farm* buyFrom)=0;
    virtual void sell_Products()=0;
    virtual void buy_Animals()=0;
    // Computes how many products did the farm produce, by summing the ages of all its animals
    int farm_production();
    virtual void updateProducts()=0;
    // Gets a pointer to a Farm and adds it to the pot_buyers vector
    void add_pot_buyer(Farm* addFarm);
    //Each Farm need to implement and update its potential buyers and what farms are they subscribes to
    virtual void add_cowFarm(Farm* addFarm)=0;
    virtual void add_sheepFarm(Farm* addFarm)=0;
    virtual void add_chickenFarm(Farm* addFarm)=0;
    virtual void addMeTo_cowFarm(Farm* addToFarm)=0;
    virtual void addMeTo_sheepFarm(Farm* addToFarm)=0;
    virtual void addMeTo_chickenFarm(Farm* addToFarm)=0;
    virtual void print_Farm()const=0;
    virtual ~Farm();
};


#endif //ASSIGNMENT4_FARM_H

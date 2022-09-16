
#ifndef ASSIGNMENT4_COWFARM_H
#define ASSIGNMENT4_COWFARM_H
#include "Farm.h"

class cowFarm: public Farm {
public:
    //Inits a cowFarm with 3 cows in it
    cowFarm();
    //getting a pointer to a Farm which is a chickenFarm and buying as much as possible eggs, updating products and balances
    virtual void buy_Products(Farm* buyFrom);
    // Selling Milk to the potential buyers (ordered by ID), which are sheepFarms
    virtual void sell_Products();
    // Buying as much cows as possible and adding them to our animals vector
    virtual void buy_Animals();
    // Adding the Milk produced in the last year to the milk in stock
    virtual void updateProducts();
    // printing farm details by the requested format
    virtual void print_Farm()const;
    // the only relevant client is a sheepFarm, and only for them we'll try to add it to our potential buyers
    virtual void add_cowFarm(Farm* addFarm){};
    virtual void add_sheepFarm(Farm* addFarm);
    virtual void add_chickenFarm(Farm* addFarm){};
    // Adding the farm only to chickenFarm's client list because cowFarm is interested in eggs
    virtual void addMeTo_cowFarm(Farm* addToFarm){};
    virtual void addMeTo_sheepFarm(Farm* addToFarm){};
    virtual void addMeTo_chickenFarm(Farm* addToFarm);
    virtual ~cowFarm();
};


#endif //ASSIGNMENT4_COWFARM_H

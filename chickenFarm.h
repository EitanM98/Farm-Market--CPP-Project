
#ifndef ASSIGNMENT4_CHICKENFARM_H
#define ASSIGNMENT4_CHICKENFARM_H
#include "Farm.h"

class chickenFarm: public Farm {
public:
    //Inits a chickenFarm with 3 chickens in it
    chickenFarm();
    //getting a pointer to a Farm which is a sheepFarm and buying as much as possible wool, updating products and balances
    virtual void buy_Products(Farm* buyFrom);
    // Selling Eggs to the potential buyers (ordered by ID), which are cowFarms
    virtual void sell_Products();
    // Buying as much chickens as possible and adding them to our animals vector
    virtual void buy_Animals();
    // Adding the Eggs produced in the last year to the Eggs in stock
    virtual void updateProducts();
    // printing farm details by the requested format
    virtual void print_Farm()const;
    // the only relevant client is a cowFarm, and only for them we'll try to add it to our potential buyers
    virtual void add_cowFarm(Farm* addFarm);
    virtual void add_sheepFarm(Farm* addFarm){};
    virtual void add_chickenFarm(Farm* addFarm){};
    // Adding the farm only to sheepFarm's client list because chickenFarm is interested in wool
    virtual void addMeTo_cowFarm(Farm* addToFarm){};
    virtual void addMeTo_sheepFarm(Farm* addToFarm);
    virtual void addMeTo_chickenFarm(Farm* addToFarm){};
    virtual ~chickenFarm();

};


#endif //ASSIGNMENT4_CHICKENFARM_H

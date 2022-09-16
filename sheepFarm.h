//
// Created by ise on 12/28/21.
//

#ifndef ASSIGNMENT4_SHEEPFARM_H
#define ASSIGNMENT4_SHEEPFARM_H
#include "Farm.h"

class sheepFarm: public Farm{
public:
    //Inits a sheepFarm with 3 sheeps in it
    sheepFarm();
    //getting a pointer to a Farm which is a cowFarm and buying as much as possible Milk, updating products and balances
    virtual void buy_Products(Farm* buyFrom);
    // Selling Wool to the potential buyers (ordered by ID), which are chickenFarms
    virtual void sell_Products();
    // Buying as much sheeps as possible and adding them to our animals vector
    virtual void buy_Animals();
    // Adding the Wool produced in the last year to the Wool in stock
    virtual void updateProducts();
    // printing farm details by the requested format
    virtual void print_Farm()const;
    // the only relevant client is a chickenFarm, and only for them we'll try to add it to our potential buyers
    virtual void add_cowFarm(Farm* addFarm){};
    virtual void add_sheepFarm(Farm* addFarm){};
    virtual void add_chickenFarm(Farm* addFarm);
    // Adding the farm only to cowFarm's client list because sheepFarm is interested in Milk
    virtual void addMeTo_cowFarm(Farm* addToFarm);
    virtual void addMeTo_sheepFarm(Farm* addToFarm){};
    virtual void addMeTo_chickenFarm(Farm* addToFarm){};
    virtual ~sheepFarm();

};


#endif //ASSIGNMENT4_SHEEPFARM_H

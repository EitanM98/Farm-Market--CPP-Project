
#ifndef ASSIGNMENT4_MARKET_H
#define ASSIGNMENT4_MARKET_H
#include <iostream>
#include <cstdio>
#include <vector>
#include "Farm.h"
#include "cowFarm.h"
#include "chickenFarm.h"
#include "sheepFarm.h"
#include "MarketExceptions.h"

using namespace std;

class Market {
private:
    int year;
    vector<Farm *> Farms;
    //private helper methods:
    // Gets input from the user, and creates the proper amount of new farms, also updates farms' clients lists
    void addFarms();
    // Iterates through all the Farms and updates how many products are available for sale
    void updateProduction();
    // all the animals in every farm are getting older by 1 year and every farm gets 10$
    void addOneYear_ToFarms();
    // Combining all the functionalities to execute one trading year
    void oneYearFastForward();
    // updates farms' clients lists
    void updatePot_buyers(Farm* farm);
    // each Farm sells its products to his potential buyers (ordered by ID)
    void beginMarket();
    // each Farm buys the proper animals with all the money left from the trading
    void buyAnimals();
    // gets Input from the user for new farms, throws exceptions if needed
    void getInput(int& cowFarms,int& sheepFarms, int& chickenFarms);
public:
    // init a Market with empty Farms vector and year is 0
    Market();
    // returns current year of trading
    int getYear()const;
    // Prints all the Farms by their print method
    void printMarketFarms()const;
    // Adding new Farms and executing a trading year
    void nextYear();
    // Execution of multiple trading years without adding new farms
    void fastForwardYears();
    // deletes first all the farms in the market and then the market itself
    ~Market();
};


#endif //ASSIGNMENT4_MARKET_H


#include "Farm.h"
int Farm::farm_num=1;

Farm::Farm() {
    ID=farm_num;
    farm_num++;
    Money=10;
    Milk* milk=new Milk();
    Egg* egg=new Egg();
    Wool* wool=new Wool();
    if(!milk || !egg || !wool)
        exit(1);
    products[0]=milk;
    products[1]=wool;
    products[2]=egg;
    animals=vector <Animal *>();
    pot_buyers=vector<Farm *>();
}

int Farm::get_Balance() const {
    return Money;
}

int Farm::get_ID() const {
    return ID;
}

void Farm::deposit_Money(int deposit) {
    if(deposit>0)
        Money+=deposit;
}

void Farm::withdraw_Money(int withdraw) {
    if(withdraw<=Money)
        Money-=withdraw;
}

int Farm::farm_production() {
    int sum=0;
    for(auto it=animals.begin();it!=animals.end();++it)
    {
        sum+=(*it)->get_age();
    }
    return sum;
}

void Farm::add_pot_buyer(Farm *addFarm) {
    if(addFarm)
        pot_buyers.push_back(addFarm);
}

Product **Farm::get_products(){
    return products;
}

void Farm::updateAnimals() {
    for(auto it=animals.begin();it!=animals.end();)
    {
        (*it)->addYear();
        if((*it)->is_too_old()){
            delete(*it);
            it=animals.erase(it);
        }
        else{
            ++it;
        }
    }
}
// Destructor first deletes all the objects in the animal vector and products array and then destroys the Farm
Farm::~Farm() {
    for(auto & product : products)
        delete product;
    for(auto & animal:animals)
        delete animal;
    pot_buyers.clear();

}
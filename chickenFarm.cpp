
#include "chickenFarm.h"


void chickenFarm::print_Farm() const {
    cout<<"Farm Id: "<<ID<<", type: Chicken Farm, Money: "<<Money<<", Animals: "<<animals.size()<<" chickens, Products: Milk["<<
        products[0]->get_quantity()<<"], Wool["<<products[1]->get_quantity()<<"], Eggs["<<products[2]->get_quantity()<<"]"<<endl;
}

chickenFarm::chickenFarm():Farm() {
    Animal* chicken1=new Chicken();
    if(!chicken1)
        exit(1);
    animals.push_back(chicken1);
    Animal* chicken2=new Chicken();
    if(!chicken2)
        exit(1);
    animals.push_back(chicken2);
    Animal* chicken3=new Chicken();
    if(!chicken3)
        exit(1);
    animals.push_back(chicken3);
}

void chickenFarm::buy_Animals() {
    int num_chickens=0;
    int total_price=0;
    int price=Chicken::get_static_price();
    while(Money>=price)
    {
        Animal* new_chicken=new Chicken();
        if(!new_chicken)
            exit(1);
        animals.push_back(new_chicken);
        this->withdraw_Money(price);
        total_price+=price;
        num_chickens++;
    }
    if(total_price>0)
        cout<<"Chicken farm("<<ID<<") bought "<<num_chickens<<" chickens for "<<total_price<<" dollars"<<endl;

}

void chickenFarm::add_cowFarm(Farm *addFarm) {
    addFarm->addMeTo_chickenFarm(this);
}

void chickenFarm::addMeTo_sheepFarm(Farm *addToFarm) {
    addToFarm->add_pot_buyer(this);
    cout<<"Sheep farm("<<addToFarm->get_ID()<<") Added Chicken farm("<<ID<<") to his client list"<<endl;
}


void chickenFarm::sell_Products() {
    vector<Farm *>::iterator it;
    it=pot_buyers.begin();
    while(products[2]->get_quantity()>0 && it!=pot_buyers.end())
    {
        (*it)->buy_Products(this);
        ++it;
    }
}

void chickenFarm::buy_Products(Farm *buyFrom) {
    Product **products_arr=buyFrom->get_products();
    Product* product=products_arr[1];
    int price=product->get_price();
    int max_quantity=product->get_quantity();
    int buy_quantity=Money/price;
    if(buy_quantity>max_quantity)
        buy_quantity=max_quantity;
    buyFrom->deposit_Money(price*buy_quantity);
    product->sell_some(buy_quantity);
    this->products[1]->add_some(buy_quantity);
    this->withdraw_Money(price*buy_quantity);
    if(buy_quantity>0)
        cout<<"Chicken farm("<<ID<<") bought "<<buy_quantity<<" wool for "<<price*buy_quantity
        <<" dollars from Sheep farm("<<buyFrom->get_ID()<<")"<<endl;
}


chickenFarm::~chickenFarm() {

}

void chickenFarm::updateProducts() {
    products[2]->add_some(farm_production());
}


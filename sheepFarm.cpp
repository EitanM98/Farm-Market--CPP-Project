
#include "sheepFarm.h"

void sheepFarm::print_Farm() const {
    cout<<"Farm Id: "<<ID<<", type: Sheep farm, Money: "<<Money<<", Animals: "<<animals.size()<<" sheep, Products: Milk["<<
        products[0]->get_quantity()<<"], Wool["<<products[1]->get_quantity()<<"], Eggs["<<products[2]->get_quantity()<<"]"<<endl;
}

sheepFarm::sheepFarm():Farm() {
    Animal* sheep1=new Sheep();
    if(!sheep1)
        exit(1);
    animals.push_back(sheep1);
    Animal* sheep2=new Sheep();
    if(!sheep2)
        exit(1);
    animals.push_back(sheep2);
    Animal* sheep3=new Sheep();
    if(!sheep3)
        exit(1);
    animals.push_back(sheep3);
}

void sheepFarm::buy_Animals() {
    int num_sheeps=0;
    int total_price=0;
    int price=Sheep::get_static_price();
    while(Money>=price)
    {
        Animal* new_sheep=new Sheep();
        if(!new_sheep)
            exit(1);
        animals.push_back(new_sheep);
        this->withdraw_Money(price);
        total_price+=price;
        num_sheeps++;
    }
    if(total_price>0)
        cout<<"Sheep farm("<<ID<<") bought "<<num_sheeps<<" sheeps for "<<total_price<<" dollars"<<endl;

}

void sheepFarm::add_chickenFarm(Farm *addFarm) {
    addFarm->addMeTo_sheepFarm(this);
}

void sheepFarm::addMeTo_cowFarm(Farm *addToFarm) {
    addToFarm->add_pot_buyer(this);
    cout<<"Cow farm("<<addToFarm->get_ID()<<") Added Sheep farm("<<ID<<") to his client list"<<endl;
}


void sheepFarm::sell_Products() {
    vector<Farm *>::iterator it;
    it=pot_buyers.begin();
    while(products[1]->get_quantity()>0 && it!=pot_buyers.end())
    {
        (*it)->buy_Products(this);
        ++it;
    }
}

void sheepFarm::buy_Products(Farm *buyFrom) {
    Product **products_arr=buyFrom->get_products();
    Product* product=products_arr[0];
    int price=product->get_price();
    int max_quantity=product->get_quantity();
    int buy_quantity=Money/price;
    if(buy_quantity>max_quantity)
        buy_quantity=max_quantity;
    buyFrom->deposit_Money(price*buy_quantity);
    product->sell_some(buy_quantity);
    this->products[0]->add_some(buy_quantity);
    this->withdraw_Money(price*buy_quantity);
    if(buy_quantity>0)
        cout<<"Sheep farm("<<ID<<") bought "<<buy_quantity<<" milk for "<<price*buy_quantity
        <<" dollars from Cow farm("<<buyFrom->get_ID()<<")"<<endl;
}


sheepFarm::~sheepFarm() {

}

void sheepFarm::updateProducts() {
    products[1]->add_some(farm_production());
}


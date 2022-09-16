
#include "cowFarm.h"

void cowFarm::print_Farm() const {
    cout<<"Farm Id: "<<ID<<", type: Cow farm, Money: "<<Money<<", Animals: "<<animals.size()<<" cows, Products: Milk["<<
    products[0]->get_quantity()<<"], Wool["<<products[1]->get_quantity()<<"], Eggs["<<products[2]->get_quantity()<<"]"<<endl;
}

cowFarm::cowFarm():Farm() {
    Animal* cow1=new Cow();
    if(!cow1)
        exit(1);
    animals.push_back(cow1);
    Animal* cow2=new Cow();
    if(!cow2)
        exit(1);
    animals.push_back(cow2);
    Animal* cow3=new Cow();
    if(!cow3)
        exit(1);
    animals.push_back(cow3);
}

void cowFarm::buy_Animals() {
    int num_cows=0;
    int total_price=0;
    int price=Cow::get_static_price();
    while(Money>=price)
    {
        Animal* new_cow=new Cow();
        if(!new_cow)
            exit(1);
        animals.push_back(new_cow);
        this->withdraw_Money(price);
        total_price+=price;
        num_cows++;
    }
    if(total_price>0)
        cout<<"Cow farm("<<ID<<") bought "<<num_cows<<" cows for "<<total_price<<" dollars"<<endl;

}

void cowFarm::add_sheepFarm(Farm *addFarm) {
    addFarm->addMeTo_cowFarm(this);
}

void cowFarm::addMeTo_chickenFarm(Farm *addToFarm) {
    addToFarm->add_pot_buyer(this);
    cout<<"Chicken farm("<<addToFarm->get_ID()<<") Added Cow farm("<<ID<<") to his client list"<<endl;
}


void cowFarm::sell_Products() {
    vector<Farm *>::iterator it;
    it=pot_buyers.begin();
    while(products[0]->get_quantity()>0 && it!=pot_buyers.end())
    {
        (*it)->buy_Products(this);
        ++it;
    }
}

void cowFarm::buy_Products(Farm *buyFrom) {
    Product **products_arr=buyFrom->get_products();
    Product* product=products_arr[2];
    int price=product->get_price();
    int max_quantity=product->get_quantity();
    int buy_quantity=Money/price;
    if(buy_quantity>max_quantity)
        buy_quantity=max_quantity;
    buyFrom->deposit_Money(price*buy_quantity);
    product->sell_some(buy_quantity);
    this->products[2]->add_some(buy_quantity);
    this->withdraw_Money(price*buy_quantity);
    if(buy_quantity>0)
        cout<<"Cow farm("<<ID<<") bought "<<buy_quantity<<" eggs for "<<price*buy_quantity
        <<" dollars from Chicken farm("<<buyFrom->get_ID()<<")"<<endl;
}

void cowFarm::updateProducts() {
    products[0]->add_some(farm_production());
}

cowFarm::~cowFarm() {

}


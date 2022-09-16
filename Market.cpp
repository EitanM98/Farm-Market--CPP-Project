
#include "Market.h"

void Market::updatePot_buyers(Farm *farm) {
    if(!farm)
        return;
    // for every farm, tries to add all the potential clients, and add it to all potential sellers
    for(auto it=Farms.begin();it!=Farms.end();++it)
    {
        farm->add_cowFarm(*it);
        farm->add_sheepFarm(*it);
        farm->add_chickenFarm(*it);
        (*it)->add_cowFarm(farm);
        (*it)->add_sheepFarm(farm);
        (*it)->add_chickenFarm(farm);
    }
}


void Market::getInput(int& cowFarms,int& sheepFarms, int& chickenFarms) {
    try {
        cout << "How many new cow farms will be added this year?" << endl;
        cin >> cowFarms;
        // Invalid input exception
        if (cowFarms < 0)
            throw CowException();
        cout << "How many new sheep farms will be added this year?" << endl;
        cin >> sheepFarms;
        if (sheepFarms < 0)
            throw SheepException();
        cout << "How many new chicken farms will be added this year?" << endl;
        cin >> chickenFarms;
        if (chickenFarms < 0)
            throw ChickenException();
    }
    catch (exception& e) {
        cout << e.what() << endl;
        getInput(cowFarms,sheepFarms, chickenFarms);
    }
}

void Market::addFarms(){
    cout<<"----Creating new farms----"<<endl;
    //Creating new farms depending on user's input
    int sheepFarms,chickenFarms,cowFarms;
    getInput(cowFarms,sheepFarms, chickenFarms);
    cout << "----Adding new farms to market----" << endl;
    // creating the farms and updating their clients and sellers lists
    for (int i = 0; i < cowFarms; i++) {
        Farm *Cow_farm = new cowFarm();
        if (!Cow_farm)
            exit(1);
        updatePot_buyers(Cow_farm);
        Farms.push_back(Cow_farm);
    }
    for (int i = 0; i < sheepFarms; i++) {
        Farm *Sheep_farm = new sheepFarm();
        if (!Sheep_farm)
            exit(1);
        updatePot_buyers(Sheep_farm);
        Farms.push_back(Sheep_farm);
    }
    for (int i = 0; i < chickenFarms; i++) {
        Farm *Chicken_farm = new chickenFarm();
        if (!Chicken_farm)
            exit(1);
        updatePot_buyers(Chicken_farm);
        Farms.push_back(Chicken_farm);
    }
}

Market::Market() {
    year=0;
    Farms=vector<Farm *>();
}

int Market::getYear() const {
    return year;
}

void Market::printMarketFarms() const {
    cout<<"----Market Farms----"<<endl;
    for(auto it= Farms.begin();it!=Farms.end();++it)
    {
        (*it)->print_Farm();
    }
}

void Market::nextYear() {
    addFarms();
    oneYearFastForward();
}


void Market::fastForwardYears() {
    int years;
    cout<<"How many years to fast forward?"<<endl;
    cin>>years;
    // Invalid input
    if(years<0){
        cout<<"Insert valid number of years";
        fastForwardYears();
    }
    // execute multiple trading years
    for (int i=0;i<years;i++){
        oneYearFastForward();
    }
}

void Market::oneYearFastForward() {
    // Handles all products available for sale
    updateProduction();
    cout<<"----Begin Market----"<<endl;
    // Handles all sales and purchases between farms
    beginMarket();
    cout<<"----Buy Animals----"<<endl;
    // Handles each farm's new animals purchases
    buyAnimals();
    year++;
    // Handles animals ages for each farm
    addOneYear_ToFarms();
}

void Market::beginMarket() {
    for(auto it=Farms.begin();it!=Farms.end();++it)
    {
        (*it)->sell_Products();
    }
}

void Market::buyAnimals() {
    for(auto it=Farms.begin();it!=Farms.end();++it)
    {
        (*it)->buy_Animals();
    }
}

void Market::addOneYear_ToFarms() {
    for(auto it=Farms.begin();it!=Farms.end();++it)
    {
        (*it)->deposit_Money(10);
        (*it)->updateAnimals();
    }
}

void Market::updateProduction() {
    for(auto it=Farms.begin();it!=Farms.end();++it)
    {
        (*it)->updateProducts();
    }
}

Market::~Market() {
    for(auto & farm:Farms)
        delete farm;
}



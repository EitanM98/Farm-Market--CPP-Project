
#ifndef ASSIGNMENT4_PRODUCT_H
#define ASSIGNMENT4_PRODUCT_H

// abstract Class Product
class Product {
protected:
    int quantity;
    int price;
public:
    Product();
    // getter methods
    int get_quantity()const;
    // each product needs to set a price and return it, pure virtual method
    virtual int get_price()const=0;
    //Gets a number to add and adds it to the products quantity
    void add_some(int add);
    //Gets a number to reduce and reduces it from the products quantity(only  if possible)
    void sell_some(int sell);
    virtual ~Product();
};


#endif //ASSIGNMENT4_PRODUCT_H

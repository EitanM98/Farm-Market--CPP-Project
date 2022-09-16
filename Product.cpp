//
// Created by ise on 12/28/21.
//

#include "Product.h"

Product::Product() {
    price=0;
    quantity=0;
}

int Product::get_quantity() const {
    return quantity;
}

int Product::get_price() const {
    return price;
}

Product::~Product() {

}

void Product::add_some(int add) {
    if(add>=0)
        quantity+=add;
}

void Product::sell_some(int sell) {
    if(quantity>=sell)
        quantity-=sell;
}


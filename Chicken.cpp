
#include "Chicken.h"
int Chicken:: static_price=3;

Chicken::~Chicken() {

}

int Chicken::get_static_price() {
    return static_price;
}

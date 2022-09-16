
#include "Cow.h"
int Cow::static_price=10;
Cow::~Cow() {

}

int Cow::get_static_price() {
    return static_price;
}

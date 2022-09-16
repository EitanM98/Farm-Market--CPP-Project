
#include "Animal.h"

Animal::Animal() {
    age=0;
    final_age=0;
    price=0;
}

Animal& Animal::operator=(const Animal &source) {
    this->price=source.price;
    this->final_age=source.final_age;
    this->age=source.age;
    return *this;
}

bool Animal::is_too_old() const {
    if(final_age<=age)
        return true;
    return false;
}

void Animal::addYear() {
    age++;
}

Animal::~Animal() {

}


#ifndef ASSIGNMENT4_MARKETEXCEPTIONS_H
#define ASSIGNMENT4_MARKETEXCEPTIONS_H
#include <exception>
#include <iostream>

using namespace std;

class CowException:public exception
{
    virtual const char* what() const throw() {
        return "Insert valid number of cow farms";
    }
};
class ChickenException:public exception
{
    virtual const char* what() const throw() {
        return "Insert valid number of chicken farms";
    }
};

class SheepException:public exception
{
    virtual const char* what() const throw() {
        return "Insert valid number of sheep farms";
    }
};

#endif //ASSIGNMENT4_MARKETEXCEPTIONS_H

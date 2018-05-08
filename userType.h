#include <iostream>
#include <cstdlib>
#include "Dictionary.h"
#ifndef userType_h
#define userType_h

class userType{
    int x,y,z;
public:
    userType(int a=0, int b=0, int c=0);
    friend istream& operator>>(istream& istr, userType &t);
    friend ostream& operator<<(ostream& ostr, userType &t);
    int operator==(userType &t);
    int operator!=(userType &t);
    userType& operator=(userType const&t);
};

#endif

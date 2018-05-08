#include <iostream>
#include <cstdlib>
#include "Dictionary.h"
#ifndef userType_h
#define userType_h

class userType{       //Typ zdefiniowany przez uzytkownika, w tym przypadku 3-wymiarowy wektor
    int x,y,z;      //Wspolrzedne wektora
public:
    userType(int a=0, int b=0, int c=0);   //konstruktor
    friend istream& operator>>(istream& istr, userType &t);
    friend ostream& operator<<(ostream& ostr, userType &t);
    int operator==(userType &t);
    int operator!=(userType &t);
    void operator=(userType const&t);
};

#endif

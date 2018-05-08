#include <iostream>
#include <cstdlib>
#include "userType.h"

using namespace std;

userType::userType(int a, int b, int c){
    x = a;
    y = b;
    z = c;
}

istream& operator>>(istream &istr, userType &t){
    istr >> t.x >> t.y >> t.z;
    return istr;
}

ostream& operator<<(ostream &ostr, userType &t){
    ostr << "[" << t.x << ";" << t.y << ";" << t.z << "]";
    return ostr;
}

int userType::operator==(userType &t){
    if(x == t.x && y == t.y && z == t.z)
        return 1;
    else
        return 0;
}

int userType::operator!=( userType &t){
    if(x == t.x && y == t.y && z == t.z)
        return 0;
    else
        return 1;
}

userType& userType::operator=(userType const&t){
    x = t.x;
    y = t.y;
    z = t.z;
}

#include <iostream>
#include <cstdlib>
#include "Dictionary.h"
#include "userType.h"
#ifndef test_h
#define test_h
using namespace std;

class test1{
private:
    Dictionary<int,int> dict1;
    Dictionary<int,int> dict2;
public:
    int add();
    int srch();
    int change();
    int comp();
    int dSize();
    void print();
    int del();
};

class test2{
private:
    Dictionary<userType,userType> dict1;
    Dictionary<userType,userType> dict2;
public:
    int add();
    int srch();
    int change();
    int comp();
    int dSize();
    void print();
    int del();
};

#endif

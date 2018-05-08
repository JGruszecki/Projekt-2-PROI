#include <iostream>
#include <cstdlib>
#include "test.h"

using namespace std;

    int test1::add(){
        if(dict1.addEntry(1,1) == 0 && dict2.addEntry(2,2) == 0){
            cout << "Dodawanie pary (klucz, wartosc) udana" << endl << endl;
            return 0;
        }
        else{
            cout << "Blad" << endl;
            return 1;
        }
    }

    int test1::del(){
        if(dict1.deleteEntry(1) == 0){
            cout << "Usuwanie pary (klucz, wartosc) udana" << endl << endl;
            return 0;
        }
        else{
            cout << "Blad" << endl;
            return 1;
        }
    }

    int test1::srch(){
        if(dict1.entrySearch(1) == 1){
            cout << "Wartosc o kluczu 1 = " << dict1.entrySearch(1) << endl;
            cout << "Wynik wyszukiwania poprawny" << endl << endl;
            return 0;
        }
        else{
            cout << "Blad" << endl;
            return 1;
        }
    }

    int test1::change(){
        if(dict1.change(1,3) == 0){
            cout << "Zmiana wartosci o danym kluczu udana" << endl << endl;
            return 0;
        }
        else{
            cout << "Blad" << endl;
            return 1;
        }
    }

    int test1::comp(){
        if(dict1.compare(&dict2) == 1){
            cout << "Slowniki sa rozne, wynik porownania poprawny" << endl << endl;
            return 0;
        }
        else{
            cout << "Blad" << endl;
            return 1;
        }
    }

    int test1::dSize(){
        if(dict1.checkSize() == 1){
            cout << "Wielkosc slownika:  " << dict1.checkSize() << endl;
            cout << "Rozmiar slownika poprawny" << endl << endl;
            return 0;
        }
        else{
            cout << "Blad" << endl;
            return 1;
        }
    }

    void test1::print(){
        cout << "Wypisywanie slownikow:" << endl;
        dict1.print();
        cout << endl;
        dict2.print();
        cout << endl;
    }

userType x(1,1,1), y(2,2,2), a(4,4,4), b(5,5,5);

int test2::add(){
        if(dict1.addEntry(x,y) == 0 && dict2.addEntry(a,b) == 0){
            cout << "Dodawanie pary (klucz, wartosc) udana" << endl << endl;
            return 0;
        }
        else{
            cout << "Blad" << endl;
            return 1;
        }
    }

    int test2::del(){
        if(dict1.deleteEntry(x) == 0){
            cout << "Usuwanie pary (klucz, wartosc) udana" << endl << endl;
            return 0;
        }
        else{
            cout << "Blad" << endl;
            return 1;
        }
    }

    int test2::srch(){
        if(dict1.entrySearch(x) == y){
            cout << "Wartosc o kluczu x = " << y << endl;
            cout << "Wynik wyszukiwania poprawny" << endl << endl;
            return 0;
        }
        else{
            cout << "Blad" << endl;
            return 1;
        }
    }

    int test2::change(){
        userType x1(1,2,3);
        if(dict1.change(x,x1) == 0){
            cout << "Zmiana wartosci o danym kluczu udana" << endl << endl;
            return 0;
        }
        else{
            cout << "Blad" << endl;
            return 1;
        }
    }

    int test2::comp(){
        if(dict1.compare(&dict2) == 1){
            cout << "Slowniki sa rozne, wynik porownania poprawny" << endl << endl;
            return 0;
        }
        else{
            cout << "Blad" << endl;
            return 1;
        }
    }

    int test2::dSize(){
        if(dict1.checkSize() == 1){
            cout << "Wielkosc slownika:  " << dict1.checkSize() << endl;
            cout << "Rozmiar slownika poprawny" << endl << endl;
            return 0;
        }
        else{
            cout << "Blad" << endl;
            return 1;
        }
    }

    void test2::print(){
        cout << "Wypisywanie slownikow:" << endl;
        dict1.print();
        cout << endl;
        dict2.print();
        cout << endl;
    }


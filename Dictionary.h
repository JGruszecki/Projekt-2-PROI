#include <iostream>
#include <cstdlib>
#ifndef Dictionary_h
#define Dictionary_h
using namespace std;

//Szablon klasy slownik, parametryzowany kluczem oraz wartoscia

template <typename KeyType, typename ValueType>
class Dictionary{
private:
    struct DictionaryEntry{         //Para klucz-wartosc
        KeyType key;
        ValueType value;
        DictionaryEntry *next;      //wskaznik na nastepny element
    };
    DictionaryEntry *head;          //Pierwszy element slownika
public:
    Dictionary(){    //Konstruktor
        DictionaryEntry *entry = new DictionaryEntry;
        entry = NULL;
        head = entry;
    }

    ~Dictionary(){       //Destruktor
        DictionaryEntry *temp = head;
        DictionaryEntry *current = head;
        if(head == NULL)
            delete head;
        else{
            while(current->next != NULL){  //Usuwanie elementow po kolei od pierwszego
                current = current->next;
                delete temp;
                temp = current;
            }
            delete current;
        }
    }

    int addEntry(KeyType key, ValueType val){      //Dodawanie elementow
        if(head == NULL){        //Jesli slownik jest pusty
            head = new DictionaryEntry;
            head->value = val;
            head->key = key;
            head->next = NULL;
            return 0;
        }
        DictionaryEntry *temp = head;
        while(temp->next != NULL){         //Sprawdzanie czy istnieje element o danym kluczu
            if(temp->key != key){
                temp = temp->next;
            }
            else{
                cout << "Istnieje juz zapis z danym kluczem!" << endl;
                return 1;
            }
        }
        DictionaryEntry *entry = new DictionaryEntry;
        entry->next = NULL;
        entry->key = key;
        entry->value = val;
        temp->next = entry;
        return 0;
    }

    int deleteEntry(KeyType key){         //Usuwanie elementow
        if(head == NULL){       //Jesli slownik jest pusty konczy dzialanie funkcji
            cout << "Slownik jest pusty!" << endl;
            return 1;
        }
        DictionaryEntry *temp = head;
        DictionaryEntry *prev;
        if(key == head->key){ //Jesli usuwamy pierwszy element
            head = temp->next;
            delete temp;
            return 0;
        }
        prev = head;
        temp = temp->next;
        while(temp->next != NULL){
            if(key == temp->key){    //Szukamy elementu o danym kluczu
                if(temp->next == NULL){
                    prev->next = NULL;
                    delete temp;
                    return 0;
                }
                prev->next = temp->next;
                delete temp;
                return 0;
            }
        }
        if(key == temp->key){     //Jesli usuwamy ostatni element
                if(temp->next == NULL){
                    prev->next = NULL;
                    delete temp;
                    return 0;
                }
                prev->next = temp->next;
                delete temp;
                return 0;
        }
        return 1;
    }

    ValueType entrySearch(KeyType key){      //Szukanie elementu o danym kluczu
        if(head == NULL){   //Jesli slownik jest pusty konczy dzialanie funkcji
            cout << "Slownik jest pusty!" << endl;
            return NULL;
        }
        DictionaryEntry *temp = head;
        while(temp->next != NULL){
            if(temp->key != key){
                temp = temp->next;
            }
            else{
                return temp->value;
            }
        }
        if(temp->key != key){
                temp = temp->next;
            }
            else{
                return temp->value;
            }
        cout << "Slownik nie zawiera wartosci o danym kluczu!" << endl;
        return NULL;
    }

    int change(KeyType key, ValueType val){            //Zmienianie elementu o danym kluczu
        if(head == NULL){
            cout << "Slownik jest pusty" << endl;
            return 1;
        }
        DictionaryEntry *temp = head;
        while(temp->next != NULL){
            if(temp->key != key){   //Szukanie elementu o danym kluczu
                temp = temp->next;
            }
            else{
                temp->value = val;
                return 0;
            }
        }
        if(temp->key != key){    //ostatni element
                temp = temp->next;
            }
            else{
                temp->value = val;
                return 0;
            }
        cout << "Slownik nie zawiera wartosci o danym kluczu!" << endl;
        return 1;
    }

    int checkSize(){      //Sprawdzanie wielkosci slownika
        int it = 0;
        if(head == NULL){      //Jesli nie ma pierwszego elementu zwraca 0
            return it;
        }
        DictionaryEntry *temp = head;
        while(temp->next != NULL){   //Zliczanie elementow
            it++;
            temp = temp->next;
        }
        return it + 1;
    }

    void print(){           //Drukowanie slownika
        if(head == NULL){
            cout << "Slownik jest pusty" << endl;
            return;
        }
        DictionaryEntry *temp = head;
        while(temp->next != NULL){
            cout << "Klucz: " << temp->key << endl;
            cout << "Wartosc: " << temp->value << endl;
            temp = temp->next;
        }
        cout << "Klucz: " << temp->key << endl;
        cout << "Wartosc: " << temp->value << endl;
        return;
    }

    int compare(Dictionary *D){          //Porownywanie slownika
        DictionaryEntry *temp = head;
        DictionaryEntry *tempD = D->head;
        if(checkSize() == 0 || D->checkSize() == 0){   //Najpierw porownoje wielkosci
            if(head == D->head)
                return 0;
            else
                return 1;
        }
        if(checkSize() != D->checkSize()){
            return 1;
        }
        while(temp->next != 0){
            if(temp->key != tempD->key || temp->value != tempD->value)       //Porownywanie kluczy i wartosci
                return 1;
            temp = temp->next;
            tempD = tempD->next;
        }
        if(temp->key != tempD->key || temp->value != tempD->value)
            return 1;
        else
            return 0;
    }
};

#endif

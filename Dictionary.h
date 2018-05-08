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
            while(current->next != NULL){
                current = current->next;
                delete temp;
                temp = current;
            }
            delete current;
        }
    }

    int addEntry(KeyType key, ValueType val){
        if(head == NULL){
            head = new DictionaryEntry;
            head->value = val;
            head->key = key;
            head->next = NULL;
            return 0;
        }
        DictionaryEntry *temp = head;
        while(temp->next != NULL){
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
    }

    int deleteEntry(KeyType key){
        if(head == NULL){
            cout << "Slownik jest pusty!" << endl;
            return 1;
        }
        DictionaryEntry *temp = head;
        DictionaryEntry *prev;
        if(key == head->key){
            head = temp->next;
            delete temp;
            return 0;
        }
        prev = head;
        temp = temp->next;
        while(temp->next != NULL){
            if(key == temp->key){
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
        if(key == temp->key){
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

    ValueType entrySearch(KeyType key){
        if(head == NULL){
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

    int change(KeyType key, ValueType val){
        if(head == NULL){
            cout << "S³ownik jest pusty" << endl;
            return 1;
        }
        DictionaryEntry *temp = head;
        while(temp->next != NULL){
            if(temp->key != key){
                temp = temp->next;
            }
            else{
                temp->value = val;
                return 0;
            }
        }
        if(temp->key != key){
                temp = temp->next;
            }
            else{
                temp->value = val;
                return 0;
            }
        cout << "Slownik nie zawiera wartosci o danym kluczu!" << endl;
        return 1;
    }

    int checkSize(){
        int it = 0;
        if(head == NULL){
            return it;
        }
        DictionaryEntry *temp = head;
        while(temp->next != NULL){
            it++;
            temp = temp->next;
        }
        return it + 1;
    }

    void print(){
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

    int compare(Dictionary *D){
        DictionaryEntry *temp = head;
        DictionaryEntry *tempD = D->head;
        if(checkSize() == 0 || D->checkSize() == 0){
            if(head == D->head)
                return 0;
            else
                return 1;
        }
        if(checkSize() != D->checkSize()){
            return 1;
        }
        while(temp->next != 0){
            if(temp->key != tempD->key || temp->value != tempD->value)
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

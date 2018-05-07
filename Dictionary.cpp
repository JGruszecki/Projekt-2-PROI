#include <iostream>
#include <cstring>
#include "Dictionary.h"

using namespace std;

template<typename KeyType, typename ValueType>
Dictionary<KeyType, ValueType>::Dictionary(){
    DictionaryEntry *entry = new DictionaryEntry;
    entry = NULL;
    head = entry;
}
template<typename KeyType, typename ValueType>
Dictionary<KeyType, ValueType>::~Dictionary(){
    DictionaryEntry *temp = head;
    DictionaryEntry *current = head;
    if(head = NULL)
        delete head;
    else{
        while(temp->next != NULL){
            delete temp;
            current = current->next;
            temp = current;
        }
        delete current;
    }
}
template<typename KeyType, typename ValueType>
int Dictionary<KeyType, ValueType>::addEntry(KeyType key, ValueType val){
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
            temp = temp->nast;
        }
        else{
            cout << "Istnieje juz zapis z danym kluczem!" << endl;
            return 1;
        }
    }
    DictionaryEntry *entry;
    temp->next = entry;
    entry->next = NULL;
    entry->key = key;
    entry->value = val;
}
template<typename KeyType, typename ValueType>
int Dictionary<KeyType, ValueType>::deleteEntry(KeyType key){
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
                prev->nast = NULL;
                delete temp;
                return 0;
            }
            prev->next = temp->next;
            delete temp;
            return 0;
        }
    }
}
template<typename KeyType, typename ValueType>
ValueType Dictionary<KeyType, ValueType>::entrySearch(KeyType key){
    if(head == NULL){
        cout << "Slownik jest pusty!" << endl;
        return NULL;
    }
    DictionaryEntry *temp = head;
    while(temp->next != NULL){
        if(temp->key != key){
            temp = temp->nast;
        }
        else{
            return temp->value;
        }
    }
    cout << "Slownik nie zawiera wartosci o danym kluczu!" << endl;
    return NULL;
}
template<typename KeyType, typename ValueType>
int Dictionary<KeyType, ValueType>::change(KeyType key, ValueType val){
    if(head == NULL){
        cout << "S³ownik jest pusty" << endl;
        return 1;
    }
    DictionaryEntry *temp = head;
    while(temp->next != NULL){
        if(temp->key != key){
            temp = temp->nast;
        }
        else{
            temp->value = val;
            return 0;
        }
    }
    cout << "Slownik nie zawiera wartosci o danym kluczu!" << endl;
    return 1;
}
template<typename KeyType, typename ValueType>
int Dictionary<KeyType, ValueType>::checkSize(){
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
template<typename KeyType, typename ValueType>
int Dictionary<KeyType, ValueType>::print(){
    if(head == NULL){
        cout << "Slownik jest pusty" << endl;
        return 1;
    }
    DictionaryEntry *temp = head;
    while(temp->next != NULL){
        cout << "Klucz: " << temp->key << endl;
        cout << "Wartosc: " << temp->value << endl;
        temp = temp->next;
    }
    cout << "Klucz: " << temp->key << endl;
    cout << "Wartosc: " << temp->value << endl;
}
template<typename KeyType, typename ValueType>
int Dictionary<KeyType, ValueType>::operator==(const Dictionary &D){
    DictionaryEntry *temp = head;
    DictionaryEntry *tempD = D.head;
    if(checkSize() == 0 || D.checkSize() == 0){
        if(head == D.head)
            return 0;
        else
            return 1;
    }
    if(checkSize() != D.checkSize()){
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

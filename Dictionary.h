#include <iostream>
#include <cstring>
#ifndef Dictionary_h
#define Dictionary_h

using namespace std;

template <typename KeyType, typename ValueType>
class Dictionary{
private:
    struct DictionaryEntry{
        KeyType key;
        ValueType value;
        DictionaryEntry *next;
    };
    DictionaryEntry *head;
public:
    Dictionary();

    ~Dictionary();

    int addEntry(KeyType key, ValueType val);

    int deleteEntry(KeyType key);

    ValueType entrySearch(KeyType key);

    int change(KeyType key, ValueType val);

    int checkSize();

    int print();

    int operator==(const Dictionary &D);
};

#endif

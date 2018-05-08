//Jakub Gruszecki, projekt 2, PROI

#include <iostream>
#include <cstdlib>
#include "Dictionary.h"
#include "test.h"
#include "userType.h"

using namespace std;

int main()
{
    test1 A;
    test2 B;

    cout << "Testy dla typu wbudowanego (int): " << endl;
    A.add();
    A.comp();
    A.dSize();
    A.srch();
    A.change();
    A.print();

    cout << "Testy dla typu zdefiniowanego przez uzytkownika: " << endl;
    A.del();
    B.add();
    B.comp();
    B.dSize();
    B.srch();
    B.change();
    B.print();
    B.del();
    return 0;
}

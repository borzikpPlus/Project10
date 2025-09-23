#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
    /*MyString obj1("Hello world");
    obj1.Print();

    MyString obj2;
    obj2.MyStrcpy(obj1);
    obj2.Print();

    cout << obj1.MyChr('H') << endl;

    cout << obj2.MyStrLen() << endl;
    obj2.MyStrCat(obj1);
    obj2.Print();
    obj2.MyDelChr('H');
    obj2.Print();*/

    MyString test1("Hello world");
    MyString test2("Hello world");
    /*cout << test1.MyStrCmp(test2) << endl;

    MyString obj3 = move(obj2);

    MyString::PrintCount();

    MyString test3("Hello world");
    MyString test4("Hello world");*/

    MyString rez1 = test1 + "Valera";
    rez1.Print();
    MyString rez2 = test1 + test2;
    rez2.Print();

    MyString rez3 = test1 - "H";
    rez3.Print();


    /*MyString rez2 = test1 + "\tWW";
    rez2.Print();*/


}
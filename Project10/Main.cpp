#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
    MyString obj1("Hello world");
    obj1.print();

    MyString obj2;
    obj2.MyStrcpy(obj1);
    obj2.print();

    cout << obj1.MyChr('H') << endl;

    cout << obj2.MyStrLen() << endl;
    obj2.MyStrCat(obj1);
    obj2.print();
    obj2.MyDelChr('H');
    obj2.print();

    MyString test1("Hello world");
    MyString test2("Hello world");
    cout << test1.MyStrCmp(test2) << endl;

    MyString obj3 = move(obj2);

    MyString::PrintCount();



}
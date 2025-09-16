#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	MyString obj1("Hello zalupa");
	obj1.print();
	
	MyString obj2 = obj1;
	obj2.print();


	obj1.MyStrStr("wo");


	obj2.MyStrcpy(obj1);
	obj2.print();
	
	cout << obj1.MyStrLen() << endl;

	obj1.MyStrCat(obj2);
	obj1.print();


}
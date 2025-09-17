#pragma once
class MyString
{
	char* str; // указатель на строку
	int length; // длина строки
public:
	MyString();
	MyString(int size);
	MyString(const char* st);
	~MyString();

	void print();

	MyString(const MyString& obj);

	void MyStrcpy(MyString& obj);// копирование строк
	bool MyStrStr(const char* str);// поиск подстроки в строке
	int  MyChr(char c); // поиск символа в строке(индекс найденного символа, либо -1)
	int MyStrLen();// возвращает длину строки
	void MyStrCat(MyString& obj); // объединение строк

	MyString(MyString&& obj);

	void MyDelChr(char c); // удаляет указанный символ 
	int MyStrCmp(MyString& b); // сравнение строк 


	// методы класса
};
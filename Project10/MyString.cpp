#include "MyString.h"
#include <iostream>



MyString::MyString()
{
	length = 89;
	str = new char [length] {};
}

MyString::MyString(int size)
{
	length = size;
	str = new char[length] {};
}

MyString::MyString(const char* st)
{
	length = strlen(st);
	str = new char[length + 1];
	strcpy_s(str, length + 1, st);
}

MyString::~MyString()
{
	delete[] str;
}

void MyString::print()
{
	std::cout << str << std::endl;
}

void MyString::MyStrcpy(MyString& obj)
{
	strcpy_s(this->str, strlen(obj.str) + 1, obj.str);
}

bool MyString::MyStrStr(const char* str)
{
	const char* s = strstr(this->str, str);
	if (s != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}

}

int MyString::MyChr(char c)
{
	for (int i = 0; i < strlen(this->str); ++i)
	{
		if (this->str[i] == c);
		{
			return i;
		}
	}
	return -1;
	
}

int MyString::MyStrLen()
{
	return strlen(this->str);
}

void MyString::MyStrCat(MyString& obj)
{
	strcat_s(this->str, strlen(obj.str) + strlen(this->str) +1, obj.str);
}

MyString::MyString(const MyString& obj)
{
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);

	std::cout << "Copy costructor\n";
}



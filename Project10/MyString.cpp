#include "MyString.h"
#include <iostream>



MyString::MyString()
{
	length = 89;
	str = new char [length] {};
	count++;
}

MyString::MyString(int size)
{
	length = size;
	str = new char[length] {};
	count++; // добавьте это
}

MyString::MyString(const char* st)
{
	length = strlen(st);
	str = new char[length + 1];
	strcpy_s(str, length + 1, st);
	count++; // добавьте это
}


MyString::~MyString()
{
	delete[] str;
}

void MyString::Print()
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
		if (this->str[i] == c)
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
	strcat_s(this->str, strlen(obj.str) + strlen(this->str) + 1, obj.str);
}

MyString::MyString(MyString&& obj)
{
	str = obj.str;
	obj.str = nullptr;
	length = obj.length;
	obj.length = length;
	std::cout << "Move constructor!\n";
}

void MyString::MyDelChr(char c)
{
	int len = strlen(this->str);
	char* result_str = new char[len + 1];


	int j = 0;
	for (int i = 0; i < len; ++i)
	{
		if (this->str[i] != c)
		{
			result_str[j++] = this->str[i];
		}
	}
	result_str[j] = '\0';

	delete[] this->str;
	this->str = result_str;
}

int MyString::MyStrCmp(MyString& obj)
{
	return strcmp(this->str, obj.str);
}

void MyString::PrintCount()
{
	std::cout << "Count -> " << count << std::endl;
}
int MyString::count = 0;




MyString MyString::operator+(const MyString& obj)
{
	size_t len1 = strlen(this->str);
	size_t len2 = strlen(obj.str);

	char* newStr = new char[len1 + len2 + 1];

	strcpy_s(newStr, len1 + 1, this->str);
	strcat_s(newStr, len1 + len2 + 1, obj.str);

	MyString result(newStr);
	delete[] newStr;

	return result;
}

MyString MyString::operator+(const char* obj)
{
	MyString result(length + 1 + strlen(obj) + 1);
	strcpy_s(result.str, length + 1, str);
	strcat_s(result.str, length + strlen(obj) + 2, obj);
	return result;
}


MyString MyString::operator-(MyString& b)
{

	return result;
}


MyString MyString::operator-(char c)
{
	int len = strlen(this->str);
	char* result_str = new char[len + 1];


	int j = 0;
	for (int i = 0; i < len; ++i)
	{
		if (this->str[i] != c)
		{
			result_str[j++] = this->str[i];
		}
	}
	result_str[j] = '\0';

	delete[] this->str;
	this->str = result_str;

	return MyString(result_str);
}




MyString::MyString(const MyString& obj)
{
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);

	std::cout << "Copy costructor\n";
}



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
	if (str && str[0] != '\0')
		std::cout << str << std::endl;
	else
		std::cout << "[empty string]" << std::endl;
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

MyString& MyString::operator++()
{
	int old_len = strlen(str);
	char* new_str = new char[old_len + 2];

	strcpy_s(new_str, old_len + 1, str);
	new_str[old_len] = '+';
	new_str[old_len + 1] = '\0';

	delete[] str;                          
	str = new_str;                         

	return *this;                          
}

MyString& MyString::operator--()
{
	int len = strlen(str);

	char* new_str = new char[len];

	for (int i = 0; i < len - 1; ++i)
		new_str[i] = str[i];

	new_str[len-1] = '\0';

	delete[] str;
	str = new_str;

	return *this;
}


MyString& MyString::operator+=(const char* obj)
{
	int old_len = strlen(this->str);
	int add_len = strlen(obj);
	int new_len = old_len + add_len + 1;

	char* new_str = new char[new_len];

	strcpy_s(new_str, new_len, this->str);

	strcat_s(new_str,new_len ,obj);

	delete[] this->str;
	this-> str = new_str;

	return *this;
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
	MyString result(*this);
	for (int i = 0; i < strlen(b.str); ++i)
	{
		result.MyDelChr(b.str[i]);
	}
	return std::move(result);
}
MyString MyString::operator-(const char* obj)
{
	MyString result(*this);
	for (int i = 0; i < strlen(obj); ++i)
	{
		result.MyDelChr(obj[i]);
	}
	return std::move(result);
}

MyString& MyString::operator=(const MyString& obj2)
{
	//1. obj = obj;
	if (this == &obj2)
	{
		return *this;
	}
	//2. obj = obj1;
	if (str != nullptr)
	{
		delete[] str;
	}
	str = new char[strlen(obj2.str) + 1];
	strcpy_s(str, strlen(obj2.str)+1,obj2.str);
	length = obj2.length;
	std::cout << "Copy = \n";
	//3
	return *this;

}


MyString::MyString(const MyString& obj)
{
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);

	std::cout << "Copy costructor\n";
}



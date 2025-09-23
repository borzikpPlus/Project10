#pragma once
class MyString
{
	char* str; // ��������� �� ������
	int length; // ����� ������
public:
	static int count;
	MyString();
	MyString(int size);
	MyString(const char* st);
	~MyString();

	void Print();

	MyString(const MyString& obj);

	void MyStrcpy(MyString& obj);// ����������� �����
	bool MyStrStr(const char* str);// ����� ��������� � ������
	int  MyChr(char c); // ����� ������� � ������(������ ���������� �������, ���� -1)
	int MyStrLen();// ���������� ����� ������
	void MyStrCat(MyString& obj); // ����������� �����

	MyString(MyString&& obj);

	void MyDelChr(char c); // ������� ��������� ������ 
	int MyStrCmp(MyString& b); // ��������� ����� 

	static void PrintCount();

	MyString operator+(const char* obj);
	MyString operator+(const MyString& obj);

	MyString operator-(const char* obj);
	MyString operator-(MyString& b);



	// ������ ������
};
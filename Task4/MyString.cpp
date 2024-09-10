#include<iostream>
#include "MyString.h"

MyString::MyString()
{
	length = 80;
	str = new char[length];

}

MyString::MyString(int Length)
{
	length = Length;
	str = new char[length];
}

MyString::MyString(const char* Str)
{
	length = strlen(Str);
	str = new char[length + 1];
	strcpy_s(str, length + 1, Str);
}

MyString::~MyString()
{
	delete[] str;
	length = 0;
}

void MyString::Input()
{
	char buf[100];
	std::cout << "Enter String: ";
	std::cin >> buf;

	if (str != nullptr)
		delete[] str;
	length = sizeof(buf); //TEST
	str = new char[length + 1];
	strcpy_s(str, length + 1, buf);
}

void MyString::Output()
{
	std::cout << "Your String: " << str << std::endl;
}

void MyString::MyStrcpy(MyString& obj)
{
	//TODO
}

bool MyString::MyStrStr(const char* str)
{
	//TODO
	return false;
}

int MyString::MyChr(char c)
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
			return i;
	}
	return -1;
}

int MyString::MyStrLen()
{
	return length;
}

void MyString::MyStrCat(MyString& b)
{
	//TODO
}

void MyString::MyDelChr(char c)
{
	//TODO
}

int MyString::MyStrCmp(MyString& b)
{
	//TODO
	return 0;
}

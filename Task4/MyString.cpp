#include<iostream>
#include "MyString.h"
using namespace std;

int cLength(const char* Ar)
{
	int len = 0;
	while (Ar[len] != '\0')
	{
		len++;
	}
	return len;
}

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
	length = cLength(Str);
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
	cout << "Enter String: ";
	cin.getline(buf, 100);

	if (str != nullptr)
		delete[] str;

	length = cLength(buf);
	str = new char[length + 1];
	strcpy_s(str, length + 1, buf);
}

void MyString::Output()
{
	cout << "String: " << str << endl;
}

void MyString::MyStrcpy(MyString& obj)
{
	if (obj.str != nullptr)
		delete[] obj.str;

	obj.length = length;
	obj.str = new char[obj.length + 1];
	for (int i = 0; i < MyStrLen(); i++)
	{
		obj.str[i] = str[i];
	}
	obj.str[obj.length] = '\0';
}

bool MyString::MyStrStr(const char* Str)
{
	for (int i = 0; i < length; i++) 
	{
		for (int j = 0; j < cLength(Str); j++) 
		{
			if (str[i + j] != Str[j]) 
			{
				break;
			}
			else if (j == cLength(Str) - 1)
			{
				return true;
			}
		}
	}

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
	return cLength(str);
}

void MyString::MyStrCat(MyString& b)
{
	char* temp = new char[MyStrLen() + b.MyStrLen() + 1];
	for (int i = 0; i < MyStrLen(); i++)
	{
		temp[i] = str[i];
	}
	for (int i = 0; i < b.MyStrLen(); i++)
	{
		temp[MyStrLen() + i] = b.str[i];
	}
	temp[MyStrLen() + b.MyStrLen()] = '\0';
	
	if (str != nullptr)
		delete[] str;

	length = cLength(temp);
	str = new char[length + 1];
	strcpy_s(str, length + 1, temp);

	delete[] temp;
}

void MyString::MyDelChr(char c)
{	
	int removedCounter = 0;
	char* temp = new char[length + 1];
	strcpy_s(temp, length + 1, str);

	for (int i = 0; i < MyStrLen(); i++)
	{
		if (temp[i] == c)
		{
			temp[i] == str[i + 1];
			removedCounter++;
		}
	}
	cout << temp << endl;
	
	if (removedCounter > 0)
	{
		length -= removedCounter;

		if (str != nullptr)
			delete[] str;

		str = new char[length + 1];
		strcpy_s(str, length + 1, temp);

		temp[MyStrLen()] = '\0';
	}
	
	delete[] temp;
}

int MyString::MyStrCmp(MyString& b)
{
	if (length == b.length)
	{
		return 0;
	} 
	else if (length < b.length) 
	{
		return -1;
	}
	else 
	{
		return 1;
	}
}

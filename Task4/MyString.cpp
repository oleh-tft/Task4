#include<iostream>
#include "MyString.h"
using namespace std;

int MyString::count = 0;

MyString::MyString()
{
	length = 80;
	str = new char[length];

	count++;
}

MyString::MyString(int Length)
{
	length = Length;
	str = new char[length];

	count++;
}

MyString::MyString(const char* Str)
{
	int len = 0;
	while (Str[len] != '\0')
	{
		len++;
	}
	length = len;

	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = Str[i];
	}
	str[length] = '\0';

	count++;
}

MyString::MyString(const MyString& obj)
{
	length = obj.length;
	str = new char[obj.length + 1];
	strcpy_s(str, obj.length + 1, obj.str);

	count++;
}

MyString::~MyString()
{
	delete[] str;
	length = 0;
	
	count--;
}

void MyString::Input()
{
	char buf[100];
	cout << "Enter String: ";
	cin.getline(buf, 100);
	MyString temp(buf);

	length = temp.MyStrLen();
	MyStrcpy(temp);
}

void MyString::Output()
{
	cout << "String: " << str << endl;
}

void MyString::MyStrcpy(MyString& obj)
{
	if (str != nullptr)
		delete[] str;

	length = obj.length;
	str = new char[length + 1];
	for (int i = 0; i < MyStrLen(); i++)
	{
		str[i] = obj.str[i];
	}
	str[length] = '\0';
}

bool MyString::MyStrStr(const char* Str)
{
	MyString temp(Str);
	for (int i = 0; i < length; i++) 
	{
		for (int j = 0; j < temp.MyStrLen(); j++)
		{
			if (str[i + j] != Str[j]) 
			{
				break;
			}
			else if (j == temp.MyStrLen() - 1)
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
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return len;
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

	MyString cpy(temp);

	length = cpy.MyStrLen();
	MyStrcpy(cpy);

	delete[] temp;
}

void MyString::MyDelChr(char c)
{	
	int removedCounter = 0;

	MyString temp(str);

	for (int i = 0; i < temp.MyStrLen(); i++) 
	{
		if (i + removedCounter == temp.MyStrLen() - 1 && temp.str[i] == c) {
			removedCounter++;
			break;
		}
		if (temp.str[i] == c)
		{
			removedCounter++;

			for (int j = i; j < temp.MyStrLen() - 1; j++)
			{
				temp.str[j] = temp.str[j + 1];
			}
			i--;
		}
	}

	if (removedCounter > 0)
	{
		length -= removedCounter;
		str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			str[i] = temp.str[i];
		}

		str[length] = '\0';
	}
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

int MyString::GetCount()
{
	return count;
}

MyString& MyString::operator=(const MyString& obj)
{
	if (this == &obj) return *this;
	if (str != nullptr) delete[] str;

	str = new char[obj.length + 1];
	strcpy_s(str, obj.length + 1, obj.str);
	length = obj.length;

	return *this;
}

char MyString::operator[](int index)
{
	if (index >= length) {
		cout << "Index out of bounds\n";
		return ' ';
	}

	return str[index];
}

void MyString::operator() ()
{
	cout << str << endl;
}
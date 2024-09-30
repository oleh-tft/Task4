#pragma once
#include<iostream>
using namespace std;

class MyString
{
	char* str;
	int length;
	static int count;
	friend ostream& operator<<(ostream& os, MyString& obj);
	friend istream& operator>>(istream& is, MyString& obj);

public:
	MyString();
	MyString(int Length);
	MyString(const char* Str);

	MyString(const MyString& obj);
	MyString& operator=(const MyString& obj);
	MyString(MyString&& obj);
	MyString& operator=(MyString&& obj);

	~MyString();

	void Input();
	void Output();
	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* str);
	int MyChr(char c);
	int MyStrLen();
	char* GetStr()const;
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);
	static int GetCount();

	char operator[] (int index);
	void operator() ();
	MyString& operator+=(const char* text);
};

MyString operator+(const char* text, MyString& b);
#pragma once
class MyString
{
	char* str;
	int length;

public:
	MyString();
	MyString(int Length);
	MyString(const char* Str);
	~MyString();
	void Input();
	void Output();
	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* str);
	int MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);
};


#include<iostream>
#include"MyString.h";

using namespace std;

void TestInput()
{
	MyString inp;
	inp.Input();
	inp.Output();
	cout << "Length: " << inp.MyStrLen() << endl;
}

void TestCopy()
{
	MyString a("Woof Woof");
	MyString b("Meow");
	a.Output();
	b.Output();
	a.MyStrcpy(b);
	a.Output();
}

void TestSubstring()
{
	MyString id("xjitasdT TestinG");
	id.Output();

	bool found = id.MyStrStr("sdT T");
	cout << found << endl;
	bool found2 = id.MyStrStr("sdT TE");
	cout << found2 << endl;
}

void TestChar()
{
	MyString id("xjitasdT TestinG");
	id.Output();
	char toSearch = 'n';
	cout << toSearch << " index: " << id.MyChr(toSearch) << endl;
}

void TestLength()
{
	MyString len("HelloLongWorld");
	cout << "Length: " << len.MyStrLen() << endl;
}

void TestConcat()
{
	MyString dog("Woof ");
	MyString cat("Meow ");
	MyString cow("Moo");
	dog.MyStrCat(cat);
	dog.Output();
	dog.MyStrCat(cow);
	dog.Output();
}

void TestDelete()
{
	MyString bad("xaxbxcdefgxx");
	bad.MyDelChr('x');
	bad.Output();
}

void TestCompare()
{
	MyString a("ooo");
	MyString b("xxxxx");
	cout << a.MyStrCmp(b) << endl;
}

int main()
{
	
	MyString obj1("String 1");
	obj1.Output();
	cout << "Length: " << obj1.MyStrLen() << endl;

	TestInput();
	TestCopy();
	TestSubstring();
	TestChar();
	TestLength();
	TestConcat();
	TestDelete();
	TestCompare();

}
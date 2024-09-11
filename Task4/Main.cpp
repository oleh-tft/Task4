#include<iostream>
#include"MyString.h";

using namespace std;

void TestLength()
{
	MyString a("four");
	cout << "Length: " << a.MyStrLen() << endl;
}

void TestCopy()
{
	MyString a("Woof Woof");
	MyString b("Meow");
	a.Output();
	b.Output();
	a.MyStrcpy(b);
	a.Output();
	b.Output();
}

void TestSubstring()
{
	MyString id("xjitasdT TestinG");

	bool found = id.MyStrStr("sdT Testin");
	id.Output();
	cout << found << endl;
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
	MyString bad("abxcxdefxg");
	bad.MyDelChr('x');
	bad.Output();
}

int main()
{
	TestDelete();
	//TestConcat();
	//TestCopy();

}
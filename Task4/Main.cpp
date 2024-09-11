#include<iostream>
#include"MyString.h";

using namespace std;

int main()
{
	MyString a("all");
	MyString b("test");
	a.Output();
	cout << a.MyStrLen() << endl;
	b.Output();
	cout << b.MyStrLen() << endl;

	a.MyStrcpy(b);
	a.Output();
	cout << a.MyStrLen() << endl;
	b.Output();
	cout << b.MyStrLen() << endl;
	//MyString a("xjitasdT");
	//cout << "T index: " << a.MyChr('T');
}
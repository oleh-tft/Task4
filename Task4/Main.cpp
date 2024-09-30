#include<iostream>
#include"MyString.h";

using namespace std;

int main()
{
	
	MyString obj1("String 1");
	obj1.Output();


	MyString obj2("t2");
	obj2.Output();
	obj2 = move(obj1);
	obj2.Output();

	MyString obj3 = move(obj2);
	obj3.Output();

	MyString obj4(5);
	cin >> obj4;
	cout << obj4;
}
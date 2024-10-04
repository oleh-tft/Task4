#include<iostream>
#include"MyString.h";

using namespace std;

int main()
{
	
	MyString obj1("First String");
	obj1.Output();

	MyString obj2("t2");
	obj2.Output();
	obj2 = move(obj1);
	obj2.Output();
	
	MyString obj3 = move(obj2);
	obj3.Output();

	MyString obj4;
	cin >> obj4;
	cout << obj4;

	obj4 += "Hello world";
	cout << obj4;

	MyString obj5;
	obj5 = "Hello" + obj4;
	cout << obj5;
	cout << obj4;

	MyString initTest{ 'C', 'o', 'n', 's', 't', 'r', 'u', 'c', 't', 'e', 'd'};
	cout << initTest;
}
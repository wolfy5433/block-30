#include <iostream>
#include <string>
#include "Array.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	int size = 5;

	int number = 1;
	Array<int> arr1(size);
	for (int i = 0; i < arr1.GetSize(); ++i)
	{
		arr1.Set(i, number * number);
		++number;
	}
	arr1.Show();
	cout << endl;

	string s = "qwery";
	Array<string> arr2(size);
	for (int i = 0; i < arr2.GetSize(); ++i)
	{
		arr2.Set(i, s);
		s = s + "q";
	}
	arr2.Show();
	cout << endl;

	char ch = 'A';
	Array<char> arr3(size);
	for (int i = 0; i < arr2.GetSize(); ++i)
	{
		arr3.Set(i, ch);
		ch += i + 1;
	}
	arr3.Show();
	cout << endl;

	float f = 3.14;
	Array<float> arr4(size);
	for (int i = 0; i < arr4.GetSize(); ++i)
	{
		arr4.Set(i, f);
		f += 1.46;
	}
	arr4.Show();
	cout << endl;

	return 0;
}
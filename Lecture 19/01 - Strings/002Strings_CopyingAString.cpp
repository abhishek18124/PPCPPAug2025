#include<iostream>
#include<string>

using namespace std;

int main() {

	string str1 = "coding";

	string str2(str1); // string str2 = str1; // here, we are creating a copy using copy-constructor
	cout << str2 << endl;

	str2[0] = 'd'; // string obj are mutable (can be modified)
	cout << str2 << endl;
	cout << str1 << endl;

	string str3;
	str3 = str1; // here, we are creating a copy using copy assignment operator
	cout << str3 << endl;

	return 0;
}
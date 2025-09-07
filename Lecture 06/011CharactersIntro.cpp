#include<iostream>

using namespace std;

int main() {

	char ch = 'A';
	cout << ch << endl;
	cout << (int)ch << endl;

	ch = 'b';
	cout << ch << endl;
	cout << (int)ch << endl;

	ch = 66; // implicite typecasting
	cout << ch << endl;

	int x = 'A'; // implicite typecasting
	cout << x << endl;

	return 0;
}
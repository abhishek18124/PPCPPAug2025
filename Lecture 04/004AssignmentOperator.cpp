#include<iostream>
#include<bitset>

using namespace std;

int main() {

	int x; // variable declaration
	x = 10; // variable assignment
	cout << "x = " << x << endl;
	cout << bitset<32>(x) << endl;

	char ch;
	ch = 'B';
	cout << "ch = " << ch << endl;

	int y;
	y = 10 + 20;
	cout << "y = " << y << endl;

	int z;
	z = -25;
	cout << "z = " << z << endl;

	cout << bitset<32>(z) << endl;

	return 0;
}
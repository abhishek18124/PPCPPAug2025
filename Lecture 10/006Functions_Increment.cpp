#include<iostream>

using namespace std;

void incr(int a) { // here, we are passing by value, so changes done to the parameter won't be reflected in the argument
	cout << a << endl;
	a++;
	cout << a << endl;
}

int main() {

	int a = 0;

	cout << a << endl;

	incr(a);

	cout << a << endl;

	return 0;
}
#include<iostream>

using namespace std;

int multiply(int a, int b) {
	// int c = a * b;
	// return c;
	return a * b; // we can return expr from C++ fn
}

int main() {

	int a = 4;
	int b = 5;

	cout << multiply(a, b) << endl;

	return 0;
}
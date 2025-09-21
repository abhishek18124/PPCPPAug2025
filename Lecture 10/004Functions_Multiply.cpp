#include<iostream>

using namespace std;

int multiply(int a, int b) {
	// int c = a * b;
	// return c;
	return a * b; // we can return expr from C++ fn
}

int main() {

	cout << multiply(2, 3) << endl;

	int ans = multiply(4, 5);

	cout << ans << endl;

	cout << multiply(10, 20) + 100 << endl;

	return 0;
}
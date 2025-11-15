#include<iostream>

using namespace std;

void f(int n) {

	// base case

	if (n == 0) {
		return; // mandatory
	}

	// recursive case

	// f(n) : print nos. from 1 to n in the inc. order

	// 1. ask your friend to print nos. from 1 to n-1 in the inc. order

	f(n - 1);

	cout << n << " ";

	return; // optional

}

int main() {

	int n = 10;

	f(n);

	return 0;
}
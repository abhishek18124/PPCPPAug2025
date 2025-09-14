#include<iostream>

using namespace std;

int main() {

	int n = 42;
	int k = 3;

	if (((n >> k) & 1) == 1) {
		// kth bit of n is set
		cout << "set" << endl;
	} else {
		// kth bit of n is not set
		cout << "not set" << endl;
	}

	if ((n >> k) & 1) {
		// kth bit of n is set
		cout << "set" << endl;
	} else {
		// kth bit of n is not set
		cout << "not set" << endl;
	}

	return 0;
}
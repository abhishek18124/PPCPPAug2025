#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		// for the ith row, print n-i+1 characters starting from 'A'
		// in the increasing order

		char ch = 'A';
		for (int j = 1; j <= n - i + 1; j++) {
			cout << ch << " ";
			ch++; // ch = ch + 1;
		}

		// print n-i+1 more char. in decreasing order

		ch--;

		for (int j = 1; j <= n - i + 1; j++) {
			cout << ch << " ";
			ch--;
		}

		cout << endl;

	}

	return 0;
}
#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int cnt = 0;

	while (n > 0) { // # iterations equal # set bits in n

		// clear the rightmost set bit of n
		n = n & (n - 1);

		cnt++;

	}

	cout << cnt << endl;

	cout << __builtin_popcount(42) << endl;

	return 0;
}

#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 2;
	bool flag = true; // assume n is a prime

	while (i <= n - 1) {

		if (n % i == 0) {
			// you've found a factor of n in the range 2 to n-1
			cout << "not prime" << endl;
			flag = false;
			break;
		}

		i = i + 1;

	}

	if (flag == true) {
		cout << "prime" << endl;
	}

	return 0;
}
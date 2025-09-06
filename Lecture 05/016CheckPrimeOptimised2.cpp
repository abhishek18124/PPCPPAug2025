#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 2;

	while (i * i <= n) {

		if (n % i == 0) {
			// you've found a factor of n
			// in the range 2 to rn
			cout << "not prime" << endl;
			break;
		}

		i = i + 1;

	}

	if (i * i > n) {
		cout << "prime" << endl;
	}

	return 0;
}
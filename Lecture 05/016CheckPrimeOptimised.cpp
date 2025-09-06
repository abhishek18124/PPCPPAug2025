#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cin >> n;

	int rn = sqrt(n);

	int i = 2;

	while (i <= rn) {

		if (n % i == 0) {
			// you've found a factor of n
			// in the range 2 to rn
			cout << "not prime" << endl;
			break;
		}

		i = i + 1;

	}

	if (i > rn) {
		cout << "prime" << endl;
	}

	return 0;
}
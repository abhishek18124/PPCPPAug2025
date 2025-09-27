#include<iostream>
#include<cmath>

using namespace std;

// 3 adv. of using fn

// 1. readability
// 2. reusability
// 3. modularity

bool isPrime(int n) {
	int i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			// you've found a factor of n in the range 2 to sqrt(n)
			return false;
		}
		i++;
	}
	// since we didn't find any factor of n in the range 2 to sqrt(n)
	return true;
}

void printPrimes(int m) {

	for (int n = 2; n <= m; n++) { // 2, 3, 4, 5, 6, 7, ... 20

		// check if n is a prime no. or not

		if (isPrime(n)) {
			cout << n << endl;
		}

	}

}

int main() {

	int m;
	cin >> m;

	printPrimes(m);

	return 0;
}
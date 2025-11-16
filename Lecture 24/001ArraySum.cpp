#include<iostream>

using namespace std;

int f(int X[], int n, int i) {

	// base case

	if (i == n) {
		// f(n) = it is a fn that finds the sum of suffix that starts at the nth index i.e. {}
		return 0;
	}

	// recursive case

	// f(i) = it is a fn that finds the sum of suffix that starts at the ith index

	// 1. ask your friend to find the sum of suffix that starts at the i+1th index

	int A = f(X, n, i + 1);

	return X[i] + A;

}

int main() {

	int X[] = {10, 20, 30, 40, 50};
	int n = sizeof(X) / sizeof(int);

	cout << f(X, n, 0) << endl;

	return 0;
}
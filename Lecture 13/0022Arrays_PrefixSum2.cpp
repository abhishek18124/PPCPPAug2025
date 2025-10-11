// constraints : 1 <= n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	int psum[101]; // based on constraints

	psum[0] = 0;

	// psum[i] = psum[i-1] + arr[i-1]

	// psum[i] stores the sum of prefix that
	// ends at the i-1th index ie. sum(arr[0..i-1])

	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + arr[i - 1];
	}

	for (int i = 0; i <= n; i++) {
		cout << psum[i] << " ";
	}

	cout << endl;

	return 0;
}
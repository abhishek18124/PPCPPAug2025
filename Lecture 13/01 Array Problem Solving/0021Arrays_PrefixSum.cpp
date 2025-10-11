// constraints : 1 <= n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	int psum[100]; // based on constraints

	psum[0] = arr[0];

	// psum[1] = psum[0] + arr[1]
	// psum[2] = psum[1] + arr[2]
	// psum[3] = psum[2] + arr[3]
	// ...
	// psum[i] = psum[i-1] + arr[i]

	// psum[i] stores the sum of prefix that
	// ends at the ith index ie. sum(arr[0..i])

	for (int i = 1; i < n; i++) {
		psum[i] = psum[i - 1] + arr[i];
	}

	for (int i = 0; i < n; i++) {
		cout << psum[i] << " ";
	}

	cout << endl;

	return 0;
}
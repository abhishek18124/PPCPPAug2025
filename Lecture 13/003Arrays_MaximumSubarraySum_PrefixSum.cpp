// constraints : n <= 100

#include<iostream>
#include<climits>

using namespace std;

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	int psum[101]; // based on constraints

	// pre-computation of prefix sums

	psum[0] = 0;
	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + arr[i - 1];
	}

	int maxSofar = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// find the sum of the subarray that starts
			// at the ith index and ends at the jth index
			int sum = psum[j + 1] - psum[i];
			maxSofar = max(maxSofar, sum);
		}
	}

	cout << maxSofar << endl;

	// time : n + n^2 ~ O(n^2)
	// space: O(n) due to psum[]

	return 0;
}
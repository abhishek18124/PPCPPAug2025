#include<iostream>

using namespace std;

int main() {

	int arr[] = {1, 4, 2, 7, 6, 3, 5};
	int n = sizeof(arr) / sizeof(int);
	int k = 4;

	// time : O(n)
	// space: O(1)

	int i = 0; // to store the start of the window
	int j = 0; // to store the end of the window

	int wsum = 0; // to store the window sum
	int maxSum;   // to track the maximum window sum

	// compute the sum of 1st window

	while (j < k) {
		wsum += arr[j];
		j++;
	}

	maxSum = wsum;

	// compute the sum for the remaining windows

	while (j < n) {

		// slide the window
		wsum -= arr[i];
		i++;
		wsum += arr[j];

		maxSum = max(maxSum, wsum);

		j++;

	}

	cout << maxSum << endl;

	return 0;
}


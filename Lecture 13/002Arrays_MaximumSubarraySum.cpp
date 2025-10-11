#include<iostream>
#include<climits>

using namespace std;

// time : O(n^3)
// explanation : we've ~n^2 subarrays, to find the sum
// of each subarray, we iterate over its elements which a
// linear time operation in the worst case so net complexity
// is ~ n^2.n ~ O(n^3)

int maximumSubarraySum(int arr[], int n) {
	int maxSofar = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// find the sum of the subarray that starts
			// at the ith index and ends at the jth index
			int sum = 0; // to track the sum of the arr[i...j]
			for (int k = i; k <= j; k++) {
				sum += arr[k];
			}
			maxSofar = max(maxSofar, sum);
			// if(sum > maxSofar) {
			// 	maxSofar = sum;
			// }
		}
	}
	return maxSofar;
}

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	cout << maximumSubarraySum(arr, n) << endl;

	return 0;
}
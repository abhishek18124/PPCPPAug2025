class Solution {
public:
	int f(const vector<int>& arr, int k, int i) {

		// base case

		if (i == n) {
			return 0;
		}

		// recursive case

		// f(i) : find the maximum sum we can get by partitioning
		// arr[i...n-1] s.t. size of each subarray should be <= k
		// and each value of the subarray is replaced with the max.
		// value of the subarray

		int maxSoFar = 0; // INT_MIN
		int maxij = arr[i]; // 0 // INT_MIN

		for (int j = i; j <= i + k - 1 and j < n; j++) {
			maxij = max(maxij, arr[j]);
			maxSoFar = max(maxSoFar, (j - i + 1) * maxij + f(arr, k, j + 1));
		}

		return maxSoFar;

	}

	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		return f(arr, k, 0);
	}
};
class Solution {
public:

	// time : O(kn)
	// space: n due to fn call stack + n due to dp[] ~ O(n)

	int f(const vector<int>& arr, int k, int i, vector<int>& dp) {

		// lookup
		if (dp[i] != -1) {
			return dp[i];
		}

		// base case

		if (i == arr.size()) {
			return  dp[i] = 0;
		}

		// recursive case

		// f(i) : find the maximum sum we can get by partitioning
		// arr[i...n-1] s.t. size of each subarray should be <= k
		// and each value of the subarray is replaced with the max.
		// value of the subarray

		int maxSoFar = 0; // INT_MIN
		int maxij = arr[i]; // 0 // INT_MIN

		for (int j = i; j <= i + k - 1 and j < arr.size(); j++) {
			maxij = max(maxij, arr[j]);
			maxSoFar = max(maxSoFar, (j - i + 1) * maxij + f(arr, k, j + 1, dp));
		}

		return  dp[i] = maxSoFar;

	}

	int maxSumAfterPartitioning(vector<int>& arr, int k) {

		vector<int> dp(arr.size() + 1, -1);
		return f(arr, k, 0, dp);
	}
};
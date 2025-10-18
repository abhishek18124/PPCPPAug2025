
// https://leetcode.com/problems/trapping-rain-water/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:

	// time : 2n ~ O(n)
	// space: n due to r[] O(n)

	int trap(vector<int>& height) {
		int n = height.size();

		// precompute r[] // r[i] = max(r[i+1], height[i])

		vector<int> r(n);
		r[n - 1] = height[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			r[i] = max(r[i + 1], height[i]);
		}

		int ans = 0;
		int maxsofar = INT_MIN; // works like li
		for (int i = 0; i < n; i++) {
			// find out the water trapped on top of the
			// ith building i.e. wi
			maxsofar = max(maxsofar, height[i]);
			int wi = min(maxsofar, r[i]) - height[i];
			ans += wi;
		}

		return ans;

	}

};

int main() {

	vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	Solution s;
	cout << s.trap(height) << endl;

	return 0;

}
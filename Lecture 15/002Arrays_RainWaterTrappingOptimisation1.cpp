
// https://leetcode.com/problems/trapping-rain-water/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

	// time : 3n ~ O(n)
	// space: 2n due to l[] and r[] O(n)

	int trap(vector<int>& height) {
		int n = height.size();

		// precompute l[] // l[i] = max(l[i-1], height[i])

		vector<int> l(n);
		l[0] = height[0];
		for (int i = 1; i < n; i++) {
			l[i] = max(l[i - 1], height[i]);
		}

		// precompute r[] // r[i] = max(r[i+1], height[i])

		vector<int> r(n);
		r[n - 1] = height[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			r[i] = max(r[i + 1], height[i]);
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			// find out the water trapped on top of the
			// ith building i.e. wi

			int wi = min(l[i], r[i]) - height[i];
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
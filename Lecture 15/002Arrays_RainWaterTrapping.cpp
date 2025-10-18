
// https://leetcode.com/problems/trapping-rain-water/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

	// time : O(n^2)
	// space: O(1)

	int trap(vector<int>& height) {
		int n = height.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			// find out the water trapped on top of the
			// ith building i.e. wi

			// li = max(height[0...i])
			int li = height[i]; // assume ith building is the tallest among all the buidlings from 0 to i
			for (int j = i - 1; j >= 0; j--) {
				li = max(li, height[j]);
			}

			// ri = max(height[i...n-1])
			int ri = height[i]; // // assume ith building is the tallest among all the buidlings from i to n-1
			for (int j = i + 1; j < n; j++) {
				ri = max(ri, height[j]);
			}

			int wi = min(li, ri) - height[i];
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
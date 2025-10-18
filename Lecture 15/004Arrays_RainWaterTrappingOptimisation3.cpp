
// https://leetcode.com/problems/trapping-rain-water/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:

	// time : O(n)
	// space: O(1)

	int trap(vector<int>& height) {
		int n = height.size();

		int i = 0;
		int j = n - 1;

		int l = INT_MIN; // to track max(height[0...i])
		int r = INT_MIN; // to track max(height[j...n-1])

		int ans = 0; // to track the total water trapped b/w buildings

		while (i <= j) {

			l = max(l, height[i]);
			r = max(r, height[j]);

			if (l < r) {

				int wi = l - height[i];
				ans += wi;
				i++;

			} else {

				int wj = r - height[j];
				ans += wj;
				j--;

			}

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
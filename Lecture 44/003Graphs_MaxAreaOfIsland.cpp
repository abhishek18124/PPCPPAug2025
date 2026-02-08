// https://leetcode.com/problems/max-area-of-island/description/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {

		int m = grid.size();
		int n = grid[0].size();

		// todo ...

	}
};

int main() {

	vector<vector<int>> grid = {
		{1, 0, 0, 1, 0},
		{1, 0, 1, 0, 0},
		{0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1},
		{1, 0, 1, 1, 0}
	};

	Solution s;
	cout << s.maxAreaOfIsland(grid) << endl;

	return 0;

}
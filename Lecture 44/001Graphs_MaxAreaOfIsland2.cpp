class Solution {
public:

	vector<int> dx = {0, 0, -1, 1};
	vector<int> dy = {1, -1, 0, 0};

	int dfs(int i, int j,
	        const vector<vector<int>>& grid,
	        vector<vector<bool>>& vis,
	        int m, int n) {
		vis[i][j] = true;
		int cnt = 1; // to track the size of the component

		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1 and !vis[nx][ny]) {
				cnt += dfs(nx, ny, grid, vis, m, n);
			}

		}

		return cnt;


	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int m = grid.size(); // no. of rows
		int n = grid[0].size();  // no. of cols
		vector<vector<bool>> vis(m, vector<bool>(n, false));
		int maxSoFar = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1 and !vis[i][j]) {
					maxSoFar = max(maxSoFar, dfs(i, j, grid, vis, m, n));
				}
			}
		}
		return maxSoFar;
	}
};
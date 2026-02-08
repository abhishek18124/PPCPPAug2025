class Solution {
public:

	int dfs(int i, int j,
	        const vector<vector<int>>& grid,
	        vector<vector<bool>>& vis,
	        int m, int n) {
		vis[i][j] = true;
		int cnt = 1; // to track the size of the component

		int nx = i;
		int ny = j + 1;
		if (nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1 and !vis[nx][ny]) {
			cnt += dfs(nx, ny, grid, vis, m, n);
		}

		nx = i;
		ny = j - 1;
		if (nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1 and !vis[nx][ny]) {
			cnt += dfs(nx, ny, grid, vis, m, n);
		}

		nx = i - 1;
		ny = j;
		if (nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1 and !vis[nx][ny]) {
			cnt += dfs(nx, ny, grid, vis, m, n);
		}

		nx = i + 1;
		ny = j;
		if (nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1 and !vis[nx][ny]) {
			cnt += dfs(nx, ny, grid, vis, m, n);
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
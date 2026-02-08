// https://leetcode.com/problems/01-matrix/

#include<iostream>
#include<vector>
#include<climits>
#include <queue>

using namespace std;

// appr1 - brute-force
// time : mn.mn ~ O(m^2n^2) if m ~ n then O(n^4)

vector<vector<int>> updateMatrix(const vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> distMat(m, vector<int>(n, INT_MAX));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				// find the manhattan dist b/w (i, j)th cell and all the other cells
				for (int ii = 0; ii < m; ii++) {
					for (int jj = 0; jj < n; jj++) {
						// manhattan dist. b/w (i,j)th and (ii,jj)th cell = |ii-i| + |jj-j|
						distMat[ii][jj] = min(distMat[ii][jj],
						                      abs(ii - i) + abs(jj - j));
					}
				}
			}
		}
	}

	return distMat;

}

// appr2 - multi-source bfs
// time : O(mn)

vector<vector<int>> updateMatrixOptimised(const vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> distMat(m, vector<int>(n, INT_MAX));

	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				// node corr. to (i, j)th cell is a source
				distMat[i][j] = 0;
				q.push({i, j});
			}
		}
	}

	vector<int> dx = {0, 0, -1, 1};
	vector<int> dy = {1, -1, 0, 0};

	while (!q.empty()) {

		pair<int, int> p = q.front();
		q.pop();

		int i = p.first;
		int j = p.second;

		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (nx >= 0 and nx < m and ny >= 0 and ny < n and distMat[nx][ny] == INT_MAX) {
				// {nx, ny} isn't visited so visit them
				q.push({nx, ny});
				// since {nx, ny} is being visited cuz of {i, j} the node
				// corr. to the (i, j)th cell is the parent of the node
				// corr. to the (nx, ny)th cell in the bfs tree hence
				distMat[nx][ny] = 1 + distMat[i][j];
			}
		}

	}

	return distMat;

}

int main() {

	vector<vector<int>> mat = {
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1},
		{0, 1, 1, 1, 0}
	};

	vector<vector<int>> distMat = updateMatrixOptimised(mat);

	int m = distMat.size();
	int n = distMat[0].size();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << distMat[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;

}
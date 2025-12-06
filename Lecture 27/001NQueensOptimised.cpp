/*

https://leetcode.com/problems/n-queens/

N Queens Problem

The problem is to place 'n' queens on an 'n x n' chessboard, so that no two queens are attacking
each other, this means that no two queens are in the same row, the same column, or the same diagonal.

Example
	Input : N = 4
	Output:
			_ Q _ _	     _ _ Q _
	        _ _ _ Q      Q _ _ _
	        Q _ _ _      _ _ _ Q
	        _ _ Q _      _ Q _ _

	        [1, 3, 0, 2] [2, 0, 3, 1]

Constraint:
	1<=n<=10

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:

	void f(int r, int n, vector<string>& board,
	       vector<vector<string>>& allBoards,
	       vector<bool>& columnStatus,
	       vector<bool>& rightDiagStatus,
	       vector<bool>& leftDiagStatus) {

		// base case

		if (r == n) { // you've managed to build a valid config of n queens
			allBoards.push_back(board);
			return;
		}

		// recursive case

		// f(r) = take decisions for queens r to n-1

		// take a decision for queen r - in which column of row r you want to place Qr

		for (int j = 0; j < n; j++) {

			// can I place Qr in the jth column of row 'r' ?

			if (columnStatus[j] == false and rightDiagStatus[r + j] == false and leftDiagStatus[(r - j) + (n - 1)] == false) { // columnStatus[j] tell if the jth column of the board is occupied or not
				// you can place Qr in the jth column of row 'r'
				board[r][j] = 'Q';
				columnStatus[j] = true;
				rightDiagStatus[r + j] = true;
				leftDiagStatus[(r - j) + (n - 1)] = true;
				f(r + 1, n, board, allBoards, columnStatus, rightDiagStatus, leftDiagStatus);
				board[r][j] = '.'; // backtracking
				columnStatus[j] = false; // backtracking
				rightDiagStatus[r + j] = false; // backtracking
				leftDiagStatus[(r - j) + (n - 1)] = false; // backtracking
			}

		}

	}

	vector<vector<string>> solveNQueens(int n) {

		vector<string> board;
		for (int i = 1; i <= n; i++) {
			string row(n, '.');
			board.push_back(row);
		}

		// for (string row : board) {
		// 	cout << row << endl;
		// }

		vector<vector<string>> allBoards;

		vector<bool> columnStatus(n, false);
		vector<bool> rightDiagStatus(2 * n - 1, false);
		vector<bool> leftDiagStatus(2 * n - 1, false);

		f(0, n, board, allBoards, columnStatus, rightDiagStatus, leftDiagStatus);

		return allBoards;

	}
};


int main() {

	int n;
	cin >> n;

	Solution s;
	vector<vector<string>> configs = s.solveNQueens(n);
	// cout << configs.size() << endl;
	for (vector<string> board : configs) {
		for (string row : board) {
			cout << row << endl;
		}
		cout << endl;
	}

	return 0;
}
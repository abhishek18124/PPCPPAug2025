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

	bool isValid(int n, const vector<string>& board, int r, int j) {

		// check if you can place Qr in the jth column of row 'r' ?

		// 1. check if there is any previously placed queen Q0 to Qr-1 along the jth column

		for (int i = r - 1; i >= 0; i--) {
			if (board[i][j] == 'Q') {
				// we've found a previously placed queen in the jth column
				// therefore you cannot place Qr in the jth column of row r
				return false;
			}
		}

		// 2. check if there is any previously placed queen Q0 to Qr-1 along the right diagonal of the jth column

		for (int i = r - 1, step = 1; i >= 0 and j + step < n; i--, step++) {
			if (board[i][j + step] == 'Q') {
				// we've found a previously placed queen in the right diag of the jth column therefore you cannot place Qr in the jth column of row r
				return false;
			}
		}

		// 3. check if there is any previously placed queen Q0 to Qr-1 along the left diagonal of the jth column

		for (int i = r - 1, step = 1; i >= 0 and j - step >= 0; i--, step++) {
			if (board[i][j - step] == 'Q') {
				// we've found a previously placed queen in the left diag of the jth column therefore you cannot place Qr in the jth column of row r
				return false;
			}
		}

		// you can place Qr in the jth column of row r

		return true;

	}

	void f(int r, int n, vector<string>& board,
	       vector<vector<string>>& allBoards) {

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

			if (isValid(n, board, r, j)) {
				// you can place Qr in the jth column of row 'r'
				board[r][j] = 'Q';
				f(r + 1, n, board, allBoards);
				board[r][j] = '.'; // backtracking
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

		f(0, n, board, allBoards);

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
#include<vector>
#include<iostream>

using namespace std;

int main() {

	// vector<vector<int>> v; // syntax for declaring a 2d vector

	// vector<vector<int>> v(3, vector<int>(4)); // by default it is init with 0

	vector<vector<int>> v(3, vector<int>(4, 1)); // here vector<> is init with 1

	int m = v.size(); // no. of rows
	int n = v[0].size(); // no. of cols

	cout << "no. of rows = " << m << endl;
	cout << "no. of cols = " << n << endl;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;
}
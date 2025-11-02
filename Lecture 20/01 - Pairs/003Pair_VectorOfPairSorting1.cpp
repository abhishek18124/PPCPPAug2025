#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	vector<pair<int, int>> v = {{3, 5}, {1, 2}, {1, 3}, {1, 1}, {2, 4}};

	for (auto [x, y] : v) {
		cout << x << " " << y << endl;
	}

	cout << endl;

	// for (pair<int, int> p : v) {
	// 	cout << p.first << " " << p.second << endl;
	// }

	// cout << endl;

	sort(v.begin(), v.end());

	/* by default vector<> of pair<> is sorted in inc. order
	based on the 1st member of the pair<> but if the 1st member
	match then sorting is done based on the second member of the
	pair<> */

	for (auto [x, y] : v) {
		cout << x << " " << y << endl;
	}

	cout << endl;

	// sort(v.begin(), v.end(), greater<pair<int, int>>());

	sort(v.rbegin(), v.rend());

	for (auto [x, y] : v) {
		cout << x << " " << y << endl;
	}

	cout << endl;

	return 0;
}
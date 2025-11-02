#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b
// otherwise return false

bool secMemCmp(pair<int, int> a, pair<int, int> b) {
	// if (a.second < b.second) {
	// 	// since we are sorting vector<> of pair<> in the inc. order
	// 	// by the second member of the pair<> when a.second is less
	// 	// than b.second we want a to be ordered before b in the
	// 	// sorted sequence
	// 	return true;
	// } else {
	// 	return false;
	// }

	return a.second < b.second;
}

int main() {

	int n;
	cin >> n;

	// vector<pair<int, int>> v;
	// for (int i = 1; i <= n; i++) {
	// 	int x, y;
	// 	cin >> x >> y;
	// 	v.push_back({x, y});
	// }

	vector<pair<int, int>> v(n);
	for (int i = 0; i <= n - 1; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), secMemCmp);

	for (auto [x, y] : v) {
		cout << x << " " << y << endl;
	}

	cout << endl;

	return 0;
}
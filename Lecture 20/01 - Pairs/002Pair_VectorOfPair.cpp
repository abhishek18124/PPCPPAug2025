#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int main() {

	vector<pair<int, int>> v; // v is vector of pair<int, int>

	cout << v.size() << endl;

	v.push_back({1, 2});
	v.push_back(make_pair(3, 4));
	v.push_back({1, 3});
	v.push_back({2, 4});
	v.push_back({1, 1});

	cout << v.size() << endl;

	for (int i = 0; i < v.size(); i++) {
		pair<int, int> p = v[i];
		cout << p.first << " " << p.second << endl;
	}

	cout << endl;


	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}

	cout << endl;

	for (pair<int, int> p : v) {
		cout << p.first << " " << p.second << endl;
	}

	cout << endl;

	for (pair<int, int> p : v) {
		int x = p.first;
		int y = p.second;
		cout << x << " " << y << endl;
	}

	cout << endl;

	for (auto [x, y] : v) {
		cout << x << " " << y << endl;
	}

	return 0;
}
/*

kruskals algorithm using disjoint set

note : nodes are numbered from 1 to n

e.g.

input :

7 9

1 2 4
1 3 5
2 4 2
2 5 7
3 4 6
3 6 9
5 6 1
5 7 3
6 7 8

output :

22

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class disjointSet {

	vector<int> parMap;
	vector<int> rankMap;

public:

	disjointSet(int n) {
		parMap.resize(n + 1);
		rankMap.resize(n + 1);
	}

	void createSet(int x) {
		parMap[x] = x;
		rankMap[x] = 0;
	}

	int findSet(int x) {
		if (parMap[x] == x) {
			return x;
		}

		return parMap[x] = findSet(parMap[x]); // path compression
	}

	void unionSet(int x, int y) {
		int lx = findSet(x);
		int ly = findSet(y);

		if (lx != ly) {

			if (rankMap[lx] == rankMap[ly]) {
				rankMap[lx]++;
			}

			if (rankMap[lx] > rankMap[ly]) {
				parMap[ly] = lx;
			} else {
				// rankMap[ly] > rankMap[lx]
				parMap[lx] = ly;
			}

		}
	}

};

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> edges; // each edge is represented by a 3-sized vector
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w, u, v});
	}

	// time : ElogE for sorting + E.const to pick n-1 safe edges ~ O(ElogE)
	// space: V for disjointSet ~ O(V)

	sort(edges.begin(), edges.end()); // when you sort a vector<> of vector<> then by default sorting is done based on 1st member of the inner vector

	disjointSet ds(n);
	for (int i = 1; i <= n; i++) { // time : V.const
		ds.createSet(i);
	}

	vector<vector<int>> ans; // to track mst edges
	int mstsum = 0;

	for (vector<int> e : edges) {
		int w = e[0]; int u = e[1]; int v = e[2];
		if (ds.findSet(u) != ds.findSet(v)) {
			// uv is a safe edge
			ans.push_back(e);
			mstsum += w;
			ds.unionSet(u, v);
			if (ans.size() == n - 1) break;
		}
	}

	cout << mstsum << endl;

	for (vector<int> e : ans) {
		int w = e[0]; int u = e[1]; int v = e[2];
		cout << u << " " << v << " : " << w << endl;
	}

	return 0;
}
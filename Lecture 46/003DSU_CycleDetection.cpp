/*

cycle detection in an undirected graph using disjoint set

note : nodes are numbered from 1 to n

e.g.

input :

4 4

1 2
2 3
3 4
4 1

output :

true

*/

#include<iostream>
#include<vector>

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

	vector<vector<int>> edges; // we are representing each edge using a 2-sized vector
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
	}

	disjointSet ds(n);

	for (int i = 1; i <= n; i++) {
		ds.createSet(i);
	}

	bool flag = false; // assume no cycle present

	for (vector<int> e : edges) {
		int u = e[0];
		int v = e[1];
		if (ds.findSet(u) != ds.findSet(v)) {
			ds.unionSet(u, v);
		} else {
			// u and v are in the same set
			// which means
			// u and v are present in the same component
			// which means
			// there is a path between u and v
			// and now
			// we've a direct edge b/w them
			// hence
			// we have a cycle
			flag = true;
			break;
		}
	}

	flag ? cout << "cycle found" << endl : cout << "no cycle found" << endl;



	return 0;
}
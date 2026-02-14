/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v and w where u, v are edge endpoints 0<=u,v<=n-1 & w is weight of the edge.

input :

5 7
0 1 10
0 2 5
1 2 3
1 3 1
2 3 9
2 4 2
3 4 8

*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w}); // comment this out if graph is directed
	}

	for (int i = 0; i < n; i++) {
		cout << i << " : ";
		for (pair<int, int> p : adj[i]) {
			int ngb = p.first;
			int wt = p.second;
			cout << "(" << ngb << ", " << wt << ") ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << i << " : ";
		for (auto [ngb, wt] : adj[i]) {
			cout << "(" << ngb << ", " << wt << ") ";
		}
		cout << endl;
	}

	return 0;

}
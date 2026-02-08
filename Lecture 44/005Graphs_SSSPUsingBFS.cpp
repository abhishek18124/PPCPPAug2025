/*

Computing SSSP using the BFS algorithm in an unweighted graph.

note : each vertex in the graph is an integer in the range [0, n-1].

e.g.

9 12

0  1
0  2
1  3
1  4
2  4
2  5
3  6
4  6
4  7
5  7
6  8
7  8

*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int s = 0; // source node

	vector<int> distMap(n);
	distMap[s] = 0;

	vector<bool> vis(n, false);
	vis[s] = true;

	vector<int> parMap(n);
	parMap[s] = -1;

	queue<int> q;
	q.push(s);

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int ngb : adj[cur]) {
			if (!vis[ngb]) {
				vis[ngb] = true;
				q.push(ngb);
				distMap[ngb] = distMap[cur] + 1; // since we are visiting ngb cuz of cur therefore cur is the parent of ngb in the bfs tree
				parMap[ngb] = cur;
			}
		}

	}

	for (int i = 0; i < n; i++) {
		cout << "dist(" << i << ") = " << distMap[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "par(" << i << ") = " << parMap[i] << endl;
	}

	int d = 8; // destintion

	vector<int> path = {d};

	while (parMap[d] != -1) {
		d = parMap[d];
		path.push_back(d);
	}

	reverse(path.begin(), path.end());

	for (int x : path) cout << x << " ";

	return 0;
}
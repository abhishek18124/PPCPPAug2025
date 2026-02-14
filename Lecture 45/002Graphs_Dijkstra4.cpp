/*

note : nodes are numbered from 0 to n - 1

dijkstra's algorithm

e.g.

input :

5 7
0 1 10
0 2 5
1 2 3
1 3 1
2 3 9
2 4 2
3 4 8

output :

0 8 5 9 7

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int INF = 1e9;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w}); // since i/p graph is undirected
	}

	int s = 0; // assume node 0 to be the src vertex

	vector<int> distMap(n, INF);
	distMap[s] = 0;

	vector<bool> ex(n, false);

	priority_queue<pair<int, int>,
	               vector<pair<int, int>>,
	               greater<pair<int, int>>> minHeap;
	minHeap.push({distMap[s], s});

	// time : O(VlogV + ElogV) ~ O(ElogV)

	while (!minHeap.empty()) {

		// pair<int, int> p = minHeap.top();
		// int dis_cur = p.first;
		// int cur = p.second;

		auto [dis_cur, cur] = minHeap.top();
		minHeap.pop();

		if (dis_cur > distMap[cur]) {
			// dis_cur is an outdated dist which means
			// we've found a better path to cur so we
			// can ignore this pair<>
			continue;
		}

		// for (pair<int, int> p : adj[cur]) {
		// 	int ngb = p.first;
		// 	int wt = p.second;
		// 	if (!ex[ngb] and distMap[ngb] > dis_cur + wt) {
		// 		// edge between cur and ngb
		// 		// is tensed so relax that
		// 		// edge
		// 		...
		// 	}
		// }


		for (auto [ngb, wt] : adj[cur]) {
			if (!ex[ngb] and distMap[ngb] > dis_cur + wt) {
				// edge between cur and ngb
				// is tensed so relax that
				// edge
				distMap[ngb] = dis_cur + wt;
				minHeap.push({distMap[ngb], ngb});
			}
		}

		ex[cur] = true;

	}

	for (int i = 0; i < n; i++) {
		cout << "dis(" << i << ") = " << distMap[i] << endl;
	}

	return 0;
}
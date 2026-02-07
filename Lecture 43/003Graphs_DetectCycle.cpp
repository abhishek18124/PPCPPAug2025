/*

Given an undirected graph, check if there exists a cycle or not.

	e.g.

	3 3

	0 1
	0 2
	1 2

*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs(int cur, int par, const vector<vector<int>>& adj, vector<bool>& vis) {

	vis[cur] = true;
	for (int ngb : adj[cur]) {
		if (!vis[ngb]) {
			// ngb is not visited
			if (dfs(ngb, cur, adj, vis)) {
				// cycle found in the subcomponent of ngb
				// hence cycle found in the component of
				// cur hence cycle found in the graph
				return true;
			}
		} else {
			// ngb is visited
			// check if the edge b/w cur and ngb is a backedge
			// or not

			// the edge b/w cur and ngb will be a backedge only
			// when ngb is not the parent of cur

			if (ngb != par) {
				// the edge b/w cur and ngb is a backedge
				// therefore we've found a cycle
				return true;
			}
		}
	}

	// no cycle found in the component of cur
	return false;

}


int main() {


	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // comment this out if gr is directed
	}

	vector<bool> vis(n, false);
	bool flag = false; // assume no cycle is present

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			// make node i as src and traverse its component using dfs
			// to check if it contains a cycle
			if (dfs(i, -1, adj, vis)) {
				flag = true;
				break;
			}
		}
	}

	if (flag) {
		cout << "cycle found" << endl;
	} else {
		cout << "cycle not found" << endl;
	}


	return 0;
}
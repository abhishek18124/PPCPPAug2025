/*

Given an directed graph, check if there exists a back-edge or not.

	e.g.

	4 4

	0 1
	1 2
	2 3
	3 0

*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs(int cur, const vector<vector<int>>& adj,
         vector<bool>& vis, vector<bool>& stackState) {

	vis[cur] = true;
	stackState[cur] = true;

	for (int ngb : adj[cur]) {
		if (!vis[ngb]) {
			// ngb is not visited
			if (dfs(ngb, adj, vis, stackState)) {
				// you've found a cycle in the subcomp of ngb
				// hence you've found a cycle in the component of cur
				return true;
			}
		} else {
			// ngb is visited

			// check if cur to ngb is a backedge or not

			// check if there is directed path from ngb to cur

			// check if ngb is present on the function call stack
			if (stackState[ngb] == true) {
				// ngb is on the fn call stack which means
				// there is a directed path from ngb to cur
				// which means cur to ngb is a backedge hence
				// we've found a cycle in the component of cur
				return true;
			}
		}
	}

	stackState[cur] = false;
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
	}

	vector<bool> vis(n, false);
	vector<bool> stackState(n, false);

	bool flag = false; // assume no cycle is present

	for (int i = 0; i < n; i++) {

		if (!vis[i]) {

			// check if there is directed cycle in the
			// component of node i

			if (dfs(i, adj, vis, stackState)) {
				// we've found a cycle in the component of
				// node i hence we've found a cycle in the graph
				flag = true;
				break;
			}

		}

	}

	if (flag) {
		cout << "cycle found" << endl;
	} else {
		cout << "no cycle found" << endl;
	}


	return 0;

}
/*

Implementation of graph search using

  breadth first search (bfs)

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

using namespace std;

// time : O(V+2E) or O(n+2m)
// space: V due to vis[] + V-1 due to queue (e.g. star graph) ~ O(V) or O(n)

void bfs(int s, const vector<vector<int>>& adj) {

  vector<bool> vis(n, false);
  queue<int> q;
  q.push(s);
  vis[s] = true;

  while (!q.empty()) {

    int cur = q.front();
    q.pop();

    // explore cur

    cout << cur << " ";
    for (int ngb : adj[cur]) {
      if (!vis[ngb]) {
        vis[ngb] = true;
        q.push(ngb);
      }
    }

  }

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

  int s = 0; // s represent the source vertex or source node

  bfs(s, adj);

  return 0;

}
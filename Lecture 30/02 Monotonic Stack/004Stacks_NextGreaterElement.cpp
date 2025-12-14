#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {

	vector<int> A = {5, 3, 6, 7, 2, 1, 4};
	int n = A.size();

	// time : O(n) e.g. 5 4 3 2 1 10 here we do 2n-1 ops on the stack
	// space: O(n) due to monotonic stack e.g. 5 4 3 2 1

	vector<int> ans(n, -1);
	stack<pair<int, int>> s; // <value, index> // to track elements for which ans is not yet known

	for (int i = 0; i < n; i++) {

		// find out the elements you've seen so far for which A[i] can be the ans
		while (!s.empty() and A[i] > s.top().first) {
			// A[i] is the ans for s.top().first
			ans[s.top().second] = A[i];
			s.pop();
		}

		s.push({A[i], i}); // since ans for A[i] is not yet found, track it on stack

	}

	for (int x : ans) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}
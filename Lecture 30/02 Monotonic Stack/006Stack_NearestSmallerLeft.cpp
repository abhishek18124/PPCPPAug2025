#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

// time : 2n-1 ops ~ O(n) e.g. i/p in dec. order
// space: O(n) due to stack<> e.g. i/p is inc. order

vector<int> f2(const vector<int>& A) {

	vector<int> ans;
	stack<int> s; // <index>

	int n = A.size();

	for (int i = 0; i < n; i++) {

		// find the index of the nearest smaller element to the left of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// there is no smaller element to the left of A[i]
			ans.push_back(-1);
		} else {
			ans.push_back(s.top());
		}

		s.push(i);

	}

	return ans;

}

int main() {

	vector<int> A = {0, 3, 5, 4, 1, 6, 2};

	vector<int> ans = f2(A);
	for (int x : ans) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}
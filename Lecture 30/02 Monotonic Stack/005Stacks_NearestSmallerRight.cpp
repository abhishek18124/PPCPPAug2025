#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

// time : 2n-1 ops ~ O(n) e.g. i/p in dec. order
// space: O(n) due to stack<> e.g. i/p is inc. order

vector<int> f1(const vector<int>& A) {

	vector<int> ans;
	stack<int> s; // <index>

	int n = A.size();

	for (int i = n - 1; i >= 0; i--) {

		// find the index of the nearest smaller element to the right of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// there is no smaller element to the right of A[i]
			ans.push_back(n);
		} else {
			ans.push_back(s.top());
		}

		s.push(i);

	}

	reverse(ans.begin(), ans.end());

	return ans;

}

int main() {

	vector<int> A = {2, 5, 1, 3, 6, 4, 0};

	vector<int> ans = f1(A);
	for (int x : ans) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}
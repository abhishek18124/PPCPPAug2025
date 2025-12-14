#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> f1(const vector<int>& A) {

	vector<int> span; // to track span for each day
	stack<pair<int, int>> s; // <value, index>

	int n = A.size();

	for (int i = 0; i < n; i++) {

		// find the index of the nearest greater element
		// to the left of A[i]

		while (!s.empty() and s.top().first <= A[i]) {
			s.pop();
		}

		int j;

		if (s.empty()) {
			// there is no greater element to the left of A[i]
			j = -1;
		} else {
			j = s.top().second;
		}

		span.push_back(i - j);

		s.push({A[i], i}); // s.push(make_pair(A[i], i));

	}

	return span;

}

vector<int> f2(const vector<int>& A) {

	vector<int> span; // to track span for each day
	stack<int> s; // <index>

	int n = A.size();

	for (int i = 0; i < n; i++) {

		// find the index of the nearest greater element
		// to the left of A[i]

		while (!s.empty() and A[s.top()] <= A[i]) {
			s.pop();
		}

		int j;

		if (s.empty()) {
			// there is no greater element to the left of A[i]
			j = -1;
		} else {
			j = s.top();
		}

		span.push_back(i - j);

		s.push(i);

	}

	return span;

}

int main() {

	vector<int> A = {100, 80, 60, 70, 60, 75, 85};

	vector<int> span = f2(A);
	for (int x : span) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
class Solution {
public:

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

	// time : 3n.const ~ O(n)
	// space: O(n) within f1() and f2() for monotonic stack

	int largestRectangleArea(vector<int>& heights) {

		vector<int> nsridx = f1(heights); // n-steps
		vector<int> nslidx = f2(heights); // n-steps

		int n = heights.size();
		int maxSoFar = 0;

		for (int i = 0; i < n; i++) { // n-steps

			int bestWidth = nsridx[i] - nslidx[i] - 1;
			int area = heights[i] * bestWidth;
			maxSoFar = max(maxSoFar, area);

		}

		return maxSoFar;

	}
};
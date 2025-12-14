class Solution {
public:

	// time : O(n) ex : + + + + ... + very big - : 2n - 1 ops
	// space: O(n) due to stack<>

	vector<int> asteroidCollision(vector<int>& asteroids) {

		stack<int> s;

		for (int ast : asteroids) {
			if (ast < 0 and !s.empty() and s.top() > 0) {
				// start collision simulation
				bool flag = true; // assume ast will survive collisions
				while (!s.empty() and s.top() > 0) {
					if (abs(ast) > s.top()) {
						s.pop();
					} else if (abs(ast) < s.top()) {
						// ast will be destroyed
						flag = false;
						break;
					} else {
						// abs(ast) == s.top()
						// ast and s.top() both will be destroyed
						flag = false;
						s.pop();
						break;
					}
				}

				if (flag) {
					// ast has survived collisions so track it
					s.push(ast);
				}

			} else {
				// just track ast
				s.push(ast);
			}
		}

		vector<int> ans;

		while (!s.empty()) {
			ans.push_back(s.top());
			s.pop();
		}

		reverse(ans.begin(), ans.end());

		return ans;

	}
};
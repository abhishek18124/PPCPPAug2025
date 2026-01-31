/*

    https://leetcode.com/problems/wildcard-matching/

*/

class Solution {
public:

    bool f(const string& s, const string& p,
           int m, int n, int i, int j,
           vector<vector<int>>& dp) {

        // lookup
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // base case
        if (i == m and j == n) {
            // check if p[n...n-1] = "" matches
            // s[m...m-1] = ""
            return dp[i][j] = true;
        }

        if (i != m and j == n) {
            // check if p[n...n-1] = "" matches
            // s[i...m-1]
            return dp[i][j] = false;
        }

        if (i == m and j != n) {
            // check if p[j...n-1] matches s[m...m-1] = ""
            bool flag = true; // assume p[j...n-1] is all *
            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false; // assumption is violated
                    break;
                }
            }
            return dp[i][j] = flag;

        }

        // recursive case

        // f(i, j) : check if p[j...n-1] matches
        // s[i..m-1]

        if (s[i] == p[j] or p[j] == '?') {
            return dp[i][j] = f(s, p, m, n, i + 1, j + 1, dp);
        } else if (p[j] == '*') {
            return dp[i][j] = f(s, p, m, n, i, j + 1, dp) or
                              f(s, p, m, n, i + 1, j, dp);
        } else {
            return dp[i][j] = false;
        }
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return f(s, p, m, n, 0, 0, dp);
    }
};
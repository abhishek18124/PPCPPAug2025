/*

    https://leetcode.com/problems/wildcard-matching/

*/

class Solution {
public:

    bool f(const string& s, const string& p,
           int m, int n, int i, int j) {
        // base case
        if (i == m and j == n) {
            // check if p[n...n-1] = "" matches
            // s[m...m-1] = ""
            return true;
        }

        if (i != m and j == n) {
            // check if p[n...n-1] = "" matches
            // s[i...m-1]
            return false;
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
            return flag;

        }

        // recursive case

        // f(i, j) : check if p[j...n-1] matches
        // s[i..m-1]

        if (s[i] == p[j] or p[j] == '?') {
            return f(s, p, m, n, i + 1, j + 1);
        } else if (p[j] == '*') {
            return f(s, p, m, n, i, j + 1) or
                   f(s, p, m, n, i + 1, j);
        } else {
            return false;
        }
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        return f(s, p, m, n, 0, 0);
    }
};
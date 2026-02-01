// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:

    int f(int i, int k, const vector<int>& prices, int n, vector<vector<int>>& dp) {

        // lookup
        if (dp[i][k] != -1) {
            return dp[i][k];
        }

        // base case

        if (i == n) {
            return dp[i][k] = 0;
        }

        if (k == 0) { // ensures we don't exceed transaction limit K
            return dp[i][k] = 0;
        }

        // recursive case

        // f(i, k) = find the maximum profit you can make by completing <=k transactions starting from the ith day

        // make a decision for the ith day

        // 1. do not buy the stock on the ith day

        int donotBuyOption = f(i + 1, k, prices, n, dp);

        // 2. buy the stock on the ith day

        int buyOptionMaxSoFar = INT_MIN;

        for (int j = i + 1; j < n; j++) {

            // sell on the jth day

            buyOptionMaxSoFar = max(buyOptionMaxSoFar,
                                    (prices[j] - prices[i]) + f(j + 1, k - 1, prices, n, dp));

        }

        return dp[i][k] = max(donotBuyOption, buyOptionMaxSoFar);

    }

    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(K + 1, -1));
        return f(0, K, prices, n, dp);
    }
};

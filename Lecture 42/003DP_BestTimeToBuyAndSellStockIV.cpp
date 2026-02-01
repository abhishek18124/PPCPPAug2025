// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:

    int f(int i, int k, const vector<int>& prices, int n) {

        // base case

        if (i == n) {
            return 0;
        }

        if (k == 0) { // ensures we don't exceed transaction limit K
            return 0;
        }

        // recursive case

        // f(i, k) = find the maximum profit you can make by completing <=k transactions starting from the ith day

        // make a decision for the ith day

        // 1. do not buy the stock on the ith day

        int donotBuyOption = f(i + 1, k, prices, n);

        // 2. buy the stock on the ith day

        int buyOptionMaxSoFar = INT_MIN;

        for (int j = i + 1; j < n; j++) {

            // sell on the jth day

            buyOptionMaxSoFar = max(buyOptionMaxSoFar,
                                    (prices[j] - prices[i]) + f(j + 1, k - 1, prices, n));

        }

        return max(donotBuyOption, buyOptionMaxSoFar);

    }

    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        return f(0, K, prices, n);
    }
};

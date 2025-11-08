class Solution {
public:

    bool f(const vector<int>& bloomDay, int m, int k, int timeLimit) {

        // can I make 'm' bouquets of 'k' adjacent flowers
        // in the given 'timeLimit' i.e. 'mid' no. of days ?

        int cntr = 0;
        int bouquetCntr = 0;

        for (int i = 0; i < bloomDay.size(); i++) {

            if (bloomDay[i] <= timeLimit) {

                // pick the ith flower

                cntr++;
                if (cntr == k) {
                    // you've managed to build a bouquet
                    bouquetCntr++;
                    cntr = 0;
                }

            } else {

                cntr = 0;

            }

        }

        return bouquetCntr >= m;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (s <= e) { // O(log(e-s).n) here e-s is the size of the search space
            int mid = s + (e - s) / 2;

            // can I make 'm' bouquets of 'k' adjacent flowers
            // in 'mid' no. of days ?

            if (f(bloomDay, m, k, mid)) {

                // you can make 'm' bouquets of 'k' adjacent flowers
                // in 'mid' no. of days

                ans = mid;
                e = mid - 1;

            } else {

                // you cannot make 'm' bouquets in 'mid' no. of days

                s = mid + 1;

            }
        }

        return ans;

    }
};
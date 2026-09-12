#define all(x) x.begin(), x.end()

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {start, end, weight, original_index}
        vector<vector<int>> arr;

        for (int i = 0; i < n; ++i) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(arr.begin(), arr.end());

        // dp[i][k] = {maximum weight using intervals from i onward,
        //             lexicographically smallest indices achieving it}
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        // dp[n][k] = {0, {}}
        for (int k = 0; k <= 4; ++k) {
            dp[n][k] = {0, {}};
        }

        // Find first interval whose start > current end.
        vector<int> nxt(n);

        for (int i = 0; i < n; ++i) {
            nxt[i] = upper_bound(
                arr.begin(),
                arr.end(),
                arr[i][1],
                [](int x, const vector<int>& v) {
                    return x < v[0];
                }
            ) - arr.begin();
        }

        for (int i = n - 1; i >= 0; --i) {

            for (int k = 1; k <= 4; ++k) {

                // ---------------- TAKE ----------------
                int idx = nxt[i];

                long long take = arr[i][2];
                vector<int> takeVec = {arr[i][3]};

                if (idx < n) {
                    take += dp[idx][k - 1].first;

                    for (int x : dp[idx][k - 1].second)
                        takeVec.push_back(x);
                }

                sort(all(takeVec));

                // ---------------- NOT TAKE ----------------
                long long notTake = dp[i + 1][k].first;
                vector<int> notTakeVec = dp[i + 1][k].second;

                // ---------------- CHOOSE ----------------
                if (take > notTake) {
                    dp[i][k] = {take, takeVec};
                }
                else if (take < notTake) {
                    dp[i][k] = {notTake, notTakeVec};
                }
                else {
                    // Same weight -> lexicographically smaller indices
                    if (takeVec < notTakeVec)
                        dp[i][k] = {take, takeVec};
                    else
                        dp[i][k] = {notTake, notTakeVec};
                }
            }
        }

        return dp[0][4].second;
    }
};
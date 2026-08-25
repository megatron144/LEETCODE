class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = n - 2; i >= 1; i--) {
            for(int j = i; j <= n - 2; j++) {
                int maxi = 0;
                for(int ind = i; ind <= j; ind++) {
                    int cost = nums[i - 1] * nums[ind] * nums[j + 1]
                             + dp[i][ind - 1]
                             + dp[ind + 1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n - 2];
    }
};
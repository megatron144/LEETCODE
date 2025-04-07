class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int N=nums.size();
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += nums[i];
        }
        if (sum & 1) return false; 
        sum /= 2;
        vector<bool> prev(sum + 1, false);
        prev[0] = true; 
        if (nums[0] <= sum) prev[nums[0]] = true; 
        for (int row = 1; row < N; row++) {
            vector<bool> curr(sum + 1, false);
            curr[0] = true;
            for (int target = 1; target <= sum; target++) {
                if (prev[target]) {
                    curr[target] = true;
                    continue;
                }
                if (target >= nums[row]) {
                    curr[target] = prev[target - nums[row]];
                }
                if (target == sum && curr[target]) return true;
            }
            prev = curr;
        }
        return prev[sum];
    }
};
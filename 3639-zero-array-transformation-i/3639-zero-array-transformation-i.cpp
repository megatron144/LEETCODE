class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> atul(n + 1, 0);
        for (auto q : queries) {
            atul[q[0]]++;
            if (q[1] + 1 < n) {
                atul[q[1] + 1]--;
            }
        }
        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr += atul[i];
            nums[i] -= curr;
            if (nums[i] < 0) nums[i]=0;
        }
        return accumulate(nums.begin(), nums.end(),0LL)==0;
    }
};
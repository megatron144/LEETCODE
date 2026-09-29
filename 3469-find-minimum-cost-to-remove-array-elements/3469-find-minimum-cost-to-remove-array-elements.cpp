class Solution {
int n;
vector<vector<int>> dp;
private:
    int mini(int prv,int idx,auto& nums){
        if(idx==n)return nums[prv];
        if(idx==n-1)return max(nums[prv],nums[idx]);
        if(dp[idx][prv]!=-1)return dp[idx][prv];
        return dp[idx][prv]=min({max(nums[idx],nums[idx+1])+mini(prv,idx+2, nums),
                                max(nums[prv],nums[idx+1])+mini(idx,idx+2, nums),
                                max(nums[prv],nums[idx])+mini(idx+1,idx+2, nums)});
    }
public:
    int minCost(vector<int>& nums) {
        n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return mini(0,1,nums);
    }
};
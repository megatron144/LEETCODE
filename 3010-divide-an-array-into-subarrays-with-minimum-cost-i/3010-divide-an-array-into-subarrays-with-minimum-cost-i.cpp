class Solution {
public:
    int minimumCost(vector<int>& nums) {
        if(nums.size()==3)return nums[0]+nums[1]+nums[2];
        int ans=nums[0];
        nums[0]=INT_MAX;
        sort(nums.begin(),nums.end());
        return ans+nums[0]+nums[1];
    }
};
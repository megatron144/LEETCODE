class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        int tar=1,tmp=original;
        for(auto x: nums)if(x%tmp == 0 && x/tmp == tar)original<<=1,tar<<=1;
        return original;
    }
};
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long cnt=0,n=nums.size();
        for(int i=n-1;i>=0;i--){
            int l=lower-nums[i],h=upper-nums[i];
            auto ll = lower_bound(nums.begin(), nums.begin() + i, l);
            auto hl = upper_bound(nums.begin(), nums.begin() + i, h) - 1;
            if (ll <= hl) {
                cnt += (hl - ll + 1);
            }
        }
        return cnt;
    }
};
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        int diff=-1,maxi=-1;
        long long ans=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            ans=max(ans,1LL*nums[i]*diff);
            diff=max(diff,maxi-nums[i]);
        }
        return ans;
    }
};
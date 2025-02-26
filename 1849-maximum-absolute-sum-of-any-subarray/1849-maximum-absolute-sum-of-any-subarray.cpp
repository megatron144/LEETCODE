class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxP=0,minN=0,curr=0;
        int ans=0;
        for(auto x: nums){
            curr+=x;
            minN=min(curr,minN);
            maxP=max(curr,maxP);
            ans=max(ans,maxP-minN);
        }
        return ans;
    }
};
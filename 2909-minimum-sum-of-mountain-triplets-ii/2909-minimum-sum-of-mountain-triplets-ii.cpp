class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int curr=nums[0],n=nums.size();
        vector<int> pre,suff(n);
        pre.push_back(curr);
        for(int i=1;i<n;i++)curr=min(curr,nums[i]),pre.push_back(curr);
        curr=nums[n-1];
        for(int i=n-1;i>=0;i--)curr=min(curr,nums[i]),suff[i]=curr;
        int mn=1e9;
        for(int i=1;i<n-1;i++)if(pre[i-1]<nums[i] && nums[i]>suff[i+1])mn=min(mn,pre[i-1]+nums[i]+suff[i+1]);
        return mn==1e9?-1:mn;
    }
};
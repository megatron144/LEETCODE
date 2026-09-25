class Solution {
public:
    long long kadane(vector<int>& nums){
        long long mn=0;
        long long curr=0;
        for(int i=0;i<nums.size();i++){
            if(curr>0)curr=nums[i];
            else curr+=nums[i];
            mn=min(mn,curr);
        }
        return mn;
    }
    long long maxValue(vector<int>& nums){
        int n=nums.size();
        long long tot=0;
        for(int i=0;i<n;i++){
            if(i%2==1)nums[i]=-nums[i];
            tot+=nums[i];
        }
        vector<int> even,odd;
        for(int i=0;i<n-1;i+=2)even.push_back(nums[i]+nums[i+1]);
        for(int i=1;i<n-1;i+=2)odd.push_back(nums[i]+nums[i+1]);
        long long mini=min(kadane(even),kadane(odd));
        return tot-2*mini;
    }
};
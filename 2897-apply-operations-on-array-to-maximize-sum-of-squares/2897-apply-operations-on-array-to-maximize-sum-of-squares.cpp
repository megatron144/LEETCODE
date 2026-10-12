class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> cnt(31,0);
        int m=1e9+7;
        for(auto& x: nums)for(int i=0;i<31;i++)if(x>>i&1)cnt[i]++;
        long long ans=0;
        for(int i=0;i<k;i++){
            long long val=0;
            for(int j=0;j<31;j++)if(cnt[j]>i)val|=1<<j;
            ans=(ans+(val%m*val%m)%m)%m;
        }
        return ans;
    }
};
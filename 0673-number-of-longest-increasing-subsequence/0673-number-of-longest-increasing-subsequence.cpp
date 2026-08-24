class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<int> dp(n+1,0),cnt(n+1,0);
        int mx=1;
        for(int i=0;i<n;i++){
            dp[i]=cnt[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[i]==dp[j]+1)cnt[i]+=cnt[j];
                    if(dp[i]<1+dp[j]){
                        dp[i]=1+dp[j];
                        cnt[i]=cnt[j];
                    }
                }
            }
            if(mx==dp[i])ans+=cnt[i];
            if(mx<dp[i])mx=dp[i],ans=cnt[i];
        }
        for(auto x: cnt)cout<<x<<" ";
        return ans;
    }
};
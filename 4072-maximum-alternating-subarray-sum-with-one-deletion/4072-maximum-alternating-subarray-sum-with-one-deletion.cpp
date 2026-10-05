class Solution {
public:
    int n;
    vector<vector<vector<long long>>>dp;
    long long inf=-1e18;
    long long f(int i,int parity,int deleted,vector<int>&nums){
        if(i==n) return inf;
        if(dp[i][parity][deleted]!=inf) return dp[i][parity][deleted];
        long long ans;
        long long take=(parity==0?nums[i]:-nums[i]);
        ans=take;
        long long next=f(i+1,1-parity,deleted,nums);
        ans=max(ans,take+next);
        if(!deleted){
            long long del=f(i+1,parity,1,nums);
            ans=max(ans,del);
        }
        return dp[i][parity][deleted]=ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        this-> n=nums.size();
        long long ans=inf;
        dp.assign(n,vector<vector<long long>>(2,vector<long long>(2,inf)));
        for(int i=0;i<n;i++){
            ans=max(ans,f(i,0,0,nums));
        }
        return ans;
    }
};
class Solution {
    vector<long long> ans;
    vector<vector<long long>> dp;
    int n;
private:
    long long cntX(auto& nums,int k,int i,int curr,int tar){
        if(i==n)return 0;
        if(dp[curr][i]!=-1)return dp[curr][i];
        long long nott=0,take=0;
        if(curr==k)nott=cntX(nums,k,i+1,curr,tar);
        int nxt=(curr==k)?nums[i]:curr*nums[i]%k;
        if(nxt==tar)take++;
        take+=cntX(nums,k,i+1,nxt,tar);
        return dp[curr][i]=take+nott;
    }
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        for(auto& x: nums)x%=k;
        n=nums.size();
        ans.resize(k,0);
        for(int i=0;i<k;i++){
            dp.assign(k+1,vector<long long> (n,-1));
            ans[i]=cntX(nums,k,0,k,i);
        }
        return ans;
    }
};
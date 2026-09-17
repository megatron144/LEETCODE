class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int prv=1e9,ans=prv,sum=0;
        vector<int> dp(n+5,0);
        for(int l=0,r=0;r<n;r++){
            sum+=arr[r];
            for(;sum>target;l++)sum-=arr[l];
            dp[r]=prv;
            if(sum==target){
                int len=r-l+1;
                if(l>0)ans=min(ans,len+dp[l-1]);
                dp[r]=min(dp[r],len);
            }
            prv=dp[r];
        }
        return ans>=1e9?-1:ans;
    }
};
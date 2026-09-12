class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n+1,1e9);
        dp[0]=-1;
        for(int i=0;i<=n;i++){
            if(dp[i]==1e9)continue;
            for(int j=1;;j++){
                int add=j*(j+1)/2;
                if(add+i>n)break;
                dp[i+add]=min(dp[i+add],dp[i]+j+1);
            }
        }
        return dp[n];
    }
};
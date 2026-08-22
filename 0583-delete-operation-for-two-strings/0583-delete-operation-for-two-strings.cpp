class Solution {
public:
    int minDistance(string s1, string s2) {
        short n=s1.size(),m=s2.size();
        vector<vector<short>> dp(n+1,vector<short> (m+1,0));
        for(short i=1;i<=n;i++){
            for(short j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return (int)(n+m-2*dp[n][m]);
    }
};
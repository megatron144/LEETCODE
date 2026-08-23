class Solution {
public:
    bool isMatch(string str, string pattern) {
        int n=pattern.length(),m=str.length();
        vector<vector<bool>> dp(n+1,vector<bool> (m+1,false));
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            bool flag=true;
            for(int j=1;j<=i;j++){
                if(pattern[j-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[i][0]=flag;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(pattern[i-1]==str[j-1] || pattern[i-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(pattern[i-1]=='*'){
                    dp[i][j]=dp[i-1][j]|dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};
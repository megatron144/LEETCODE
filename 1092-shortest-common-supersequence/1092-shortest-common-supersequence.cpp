class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        short n=s1.size(),m=s2.size();
        vector<vector<short>> dp(n+1,vector<short> (m+1,0));
        for(short i=1;i<=n;i++){
            for(short j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        short i=n,j=m;
        string ans="";
        while(i && j && dp[i][j]){
            if(s1[i-1]==s2[j-1])ans.push_back(s1[i-1]),--i,--j;
            else{
                if(dp[i-1][j]>dp[i][j-1])ans.push_back(s1[--i]);
                else ans.push_back(s2[--j]);
            }
        }
        while(i)ans.push_back(s1[--i]);
        while(j)ans.push_back(s2[--j]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int m=a.length(),n=b.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[j-1]==b[i-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string ans="";
        int i=n,j=m;
        while(i && j && dp[i][j]){
            if (a[j - 1] == b[i - 1]) {
                ans.push_back(a[j - 1]);   
                i--;
                j--;
            } 
            else if(dp[i - 1][j] > dp[i][j - 1]){
                ans.push_back(b[i-1]);
                i--;
            } else {
                ans.push_back(a[j-1]);
                j--;
            }
        }
        while(i>0)ans.push_back(b[--i]);
        while(j>0)ans.push_back(a[--j]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
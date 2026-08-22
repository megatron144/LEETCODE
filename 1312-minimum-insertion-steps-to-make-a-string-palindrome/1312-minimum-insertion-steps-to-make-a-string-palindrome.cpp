class Solution {
    vector<vector<short>> dp;
private:
    short solve(string& s,int i,int j){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=((i==j)?1:2)+solve(s,i+1,j-1);
        }
        return dp[i][j]=max(solve(s,i+1,j),solve(s,i,j-1));
    }
public:
    int minInsertions(string s) {
        int n=s.size();
        dp.resize(n,vector<short> (n,-1));
        return n-(int)solve(s,0,n-1);
    }
};
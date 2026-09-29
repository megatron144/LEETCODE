class Solution {
int n,m,open,close;
vector<vector<vector<short>>> dp;
private:
    bool check(auto& grid,int i,int j,int cnt){
        if(cnt<close)return false;
        if(i==m-1 && j==n-1)return (cnt==(close+1));
        if(dp[i][j][cnt]!=-1)return (dp[i][j][cnt]==1);
        bool flg=false;
        if(i<m-1)flg|=check(grid,i+1,j,(grid[i][j]=='(')?cnt+1:cnt-1);
        if(flg){
            dp[i][j][cnt]=1;
            return true;
        }
        if(j<n-1)flg|=check(grid,i,j+1,(grid[i][j]=='(')?cnt+1:cnt-1);
        dp[i][j][cnt]=flg?1:0;
        return flg;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        if(grid[0][0]==')' || grid[m-1][n-1]=='(' || (m+n+1)&1)return false;
        open=0;
        for(auto& x: grid)for(auto& y: x)if(y=='(')open++;
        close=m*n-open;
        dp.assign(m,vector<vector<short>> (n,vector<short> (open+close+5,-1)));
        
        return check(grid,0,0,close);
    }
};
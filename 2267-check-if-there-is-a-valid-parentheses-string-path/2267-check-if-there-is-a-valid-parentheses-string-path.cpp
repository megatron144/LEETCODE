class Solution {
int n,m;
vector<vector<vector<short>>> dp;
private:
    bool check(auto& grid,int i,int j,int cnt){
        if(cnt<0)return false;
        if(i==m-1 && j==n-1)return !cnt;
        int rem=(m-1-i)+(n-1-j);
        if(cnt>rem)return false;
        if(dp[i][j][cnt]!=-1)return (dp[i][j][cnt]==1);
        bool flg=false;
        if(i<m-1)flg|=check(grid,i+1,j,(grid[i+1][j]=='(')?cnt+1:cnt-1);
        if(flg){
            dp[i][j][cnt]=1;
            return true;
        }
        if(j<n-1)flg|=check(grid,i,j+1,(grid[i][j+1]=='(')?cnt+1:cnt-1);
        dp[i][j][cnt]=flg?1:0;
        return flg;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        if(grid[0][0]==')' || grid[m-1][n-1]=='(' || (m+n+1)&1)return false;
        dp.assign(m,vector<vector<short>> (n,vector<short> (105,-1)));
        return check(grid,0,0,1);
    }
};
class Solution {
public:
    long long fill(vector<vector<int>>& grid, int i, int j) {
        if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || !grid[i][j])return 0;
        long long sum=grid[i][j];
        grid[i][j]=0;
        sum+=fill(grid,i+1,j);
        sum+=fill(grid,i-1,j);
        sum+=fill(grid,i,j+1);
        sum+=fill(grid,i,j-1);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(!grid[i][j])continue;
                if(fill(grid,i,j)%k==0)cnt++;
            }
        }
        return cnt;
    }
};
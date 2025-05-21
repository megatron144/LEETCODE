class Solution {
public:
    void setZeroes(vector<vector<int>>& grid) {
        unordered_set<int> rows,cols;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j]){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(auto x: rows){
            for(int i=0;i<n;i++)grid[x][i]=0;
        }
        for(auto x: cols){
            for(int i=0;i<m;i++)grid[i][x]=0;
        }
    }
};
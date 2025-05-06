class Solution {
private:
    int valueAt(int x,int y,int n) {
        int res=0;
        for(int k=n-1;k>=0;--k) {
            int bx=(x>>k)&1;
            int by=(y>>k)&1;
            int quad;
            if(bx==0 && by==0)quad=3;
            else if(bx==1 && by==1)quad=1;
            else if(bx==1 && by==0)quad=2;
            else quad=0;
            res+=quad<<(2*k);
        }
        return res+1;
    }

public:
    vector<vector<int>> specialGrid(int n) {
        int sz=1<<n;
        vector<vector<int>> grid(sz,vector<int>(sz));
        for(int i=0;i<sz;++i){
            for(int j=0;j<sz;++j){
                grid[i][j]=valueAt(i,j,n)-1;
            }
        }
        return grid;
    }
};

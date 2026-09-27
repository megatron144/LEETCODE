class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int c0,c1,c2,b0,b1,b2;
        c0=c1=c2=b0=b1=b2=0;
        int n=grid.size();
        for(int i=0;i<=n/2;i++){
            if(grid[i][i]==0)c0++;
            else if(grid[i][i]==1)c1++;
            else c2++;
        }
        for(int i=0;i<n/2;i++){
            if(grid[i][n-i-1]==0)c0++;
            else if(grid[i][n-i-1]==1)c1++;
            else c2++;
        }
        for(int i=n/2+1;i<n;i++){
            if(grid[i][n/2]==0)c0++;
            else if(grid[i][n/2]==1)c1++;
            else c2++;
        }
        int a,b,c;
        a=b=c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)a++;
                else if(grid[i][j]==1)b++;
                else c++;
            }
        }
        b0=a-c0,b1=b-c1,b2=c-c2;
        int mn=n*n;
        //y !y
        //0 1
        mn=min(mn,c1+c2+b0+b2);
        //1 0
        mn=min(mn,c0+c2+b1+b2);
        //0 2
        mn=min(mn,c1+c2+b0+b1);
        //2 0
        mn=min(mn,c1+c0+b1+b2);
        //1 2
        mn=min(mn,c0+c2+b0+b1);
        //2 1
        mn=min(mn,c0+c1+b0+b2);
        return mn;
    }
};
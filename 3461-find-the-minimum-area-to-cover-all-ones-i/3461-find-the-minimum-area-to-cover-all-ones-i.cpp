class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        int rL=1e9,rH=-1,cL=1e9,cH=-1;
        bool rowF=true;
        for(int i=0;i<n;i++){
            int cnt=0;
            bool first=true;
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    cnt++;
                    if(first){
                        cL=min(cL,j);
                        first=false;
                    }
                    cH=max(j,cH);
                }
            }
            if(cnt){
                if(rowF){
                    rowF=false;
                    rL=i;
                }
                rH=i;
            }
        }
        return (rH-rL+1)*(cH-cL+1);
    }
};
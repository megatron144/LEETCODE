class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        for(auto& x:dig)vis[x[0]][x[1]]=1;
        int cnt=0;
        for(auto& x :artifacts){
            int r1=x[0],c1=x[1],r2=x[2],c2=x[3];
            bool flg=true;
            for(int i=r1;i<=r2;i++)
                for(int j=c1;j<=c2;j++)
                    if(!vis[i][j])flg=false;
            if(flg)cnt++;
        }
        return cnt;
    }
};
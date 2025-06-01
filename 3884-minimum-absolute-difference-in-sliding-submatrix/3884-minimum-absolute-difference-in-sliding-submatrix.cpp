class Solution{
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>&grid,int k){
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>ans(n-k+1,vector<int>(m-k+1));
        for(int i=0;i+k<=n;i++){
            for(int j=0;j+k<=m;j++){
                set<int>st;
                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++)st.insert(grid[x][y]);
                }
                if(st.size()==1)ans[i][j]=0;
                else{
                    long long mini=1e11;
                    auto it=st.begin();
                    long long curr=*it;++it;
                    while(it!=st.end()){
                        long long nxt=*it;
                        mini=min(mini,nxt-curr);
                        curr=nxt;++it;
                    }
                    ans[i][j]=mini;
                }
            }
        }
        return ans;
    }
};

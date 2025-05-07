class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<long long,int>>q;
        vector<pair<int,int>>d={{-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<long long>>dis(n,vector<long long>(m,1e18));
        q.push({0,0});
        dis[0][0]=0;
        long long time=0;
        while(q.size()){
            auto [cost,xy]=q.front();
            q.pop();
            int x=xy/m;
            int y=xy%m;
            for(auto &it:d){
                int nx=x+it.first;
                int ny=y+it.second;
                if(nx>=0&&ny>=0&&nx<n&&ny<m){
                    time=cost+1;
                    long long actualTime=max(time,1ll*mat[nx][ny]+1);
                    if(actualTime<dis[nx][ny]){
                        dis[nx][ny]=actualTime;
                        q.push({dis[nx][ny],nx*m+ny});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};
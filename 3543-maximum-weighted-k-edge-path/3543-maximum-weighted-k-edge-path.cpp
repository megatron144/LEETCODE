class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int K, int t) {
        if(!K)return 0;
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<set<int>>> dp(n,vector<set<int>>(K+1));
        for(auto& x: edges)adj[x[0]].push_back({x[1],x[2]});
        for(int i=0;i<n;i++)dp[i][0].insert(0);
        for(int k=0;k<K;k++){
            for(int i=0;i<n;i++){
                for(auto& [v, wt] : adj[i]){
                    for(auto& w : dp[i][k]){
                        int nw=w+wt;
                        if(nw<t)dp[v][k+1].insert(nw);
                    }
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++)if(!dp[i][K].empty())mx=max(mx,*prev(dp[i][K].end()));
        return mx?mx:-1;
    }
};
class Solution {
    vector<vector<int>> mp;
    vector<int> odd_cnt,vis;
    int mark=1;
    vector<vector<int>> adj;
private:
    void dfs(int node,int par,vector<int>& nums){
        vis[node]=1;
        mp[mark].push_back(nums[node]);
        odd_cnt[mark]+=(node&1);
        for(auto& v: adj[node])if(!vis[v])dfs(v,node,nums);
    }
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n=nums.size();
        vis.resize(n,0);
        adj.resize(n);
        mp.resize(n+1);
        odd_cnt.resize(n+1,0);
        for(auto x: swaps){
            int a=x[0],b=x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            dfs(i,-1,nums);
            mark++;
        }
        long long ans=0;
        for(int i=1;i<mark;i++){
            sort(mp[i].rbegin(),mp[i].rend());
            int size_pos=mp[i].size()-odd_cnt[i];
            for(int j=0;j<mp[i].size();j++){
                if(j<size_pos)ans+=(long long)mp[i][j];
                else ans-=(long long)mp[i][j];
            }
        }
        return ans;
    }
};
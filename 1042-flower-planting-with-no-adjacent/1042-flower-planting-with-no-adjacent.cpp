class Solution {
vector<int> ans;
vector<vector<int>> adj;
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        ans.assign(n,0);
        adj.assign(n,{});
        for(auto& x: paths)adj[x[0]-1].push_back(x[1]-1),adj[x[1]-1].push_back(x[0]-1);
        for(int i=0;i<n;i++){
            int col[5]={};
            for(auto& x: adj[i])col[ans[x]]=1;
            for(int j=4;j>=1;j--)if(!col[j])ans[i]=j;
        }
        return ans;
    }
};
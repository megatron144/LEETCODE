class UnionFind {
public:
    int root[100000], Size[100000];
    UnionFind(int N){
        iota(root, root+N, 0);
        fill(Size, Size+N, 1);    
    }
    
    int Find(int x) {
        return (x==root[x]) ? x : root[x] = Find(root[x]);
    }

    bool Union(int x, int y) {       
        x=Find(x), y=Find(y);
        if (x == y) return 0; //already have same root
        if (Size[x] > Size[y]) {
            Size[x] +=Size[y];
            root[y] = x;
        } 
        else {
            Size[y] += Size[x];
            root[x] = y;
        }       
        return 1;// merge 2 disjoint sets
    } 
    bool connected(int x, int y) {
        return Find(x) == Find(y);
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) 
    {
        UnionFind graph(n);
        vector<unsigned> cost(n, UINT_MAX);
        for (auto& vec: edges){
            int u=vec[0], v=vec[1], w=vec[2];
            int wt=cost[graph.Find(u)] & cost[graph.Find(v)] & w;
            graph.Union(u, v);
            int rt=graph.Find(u);
            cost[rt]&=wt;
        }
        int m=query.size();
        vector<int> ans(m, -1);
        for(int i=0; i<m; i++){
            int s=query[i][0], t=query[i][1];
            if (graph.connected(s, t))
                ans[i]=cost[graph.Find(s)];
        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
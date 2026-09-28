class Solution {
    vector<int> tree;
    void upd(int node,int st,int en,int idx,int val){
        if(st==en){tree[node]=val;return;}
        int mid=st+(en-st)/2;
        if(idx<=mid)upd(node*2,st,mid,idx,val);
        else upd(node*2+1,mid+1,en,idx,val);
        tree[node]=max(tree[node*2],tree[node*2+1]);
    }
    int maxQ(int node,int st,int en,int l,int r){
        if(r<st || en<l)return 0;
        if(l<=st && r>=en)return tree[node];
        int mid=st+(en-st)/2;
        int lM=maxQ(node*2,st,mid,l,r);
        int rM=maxQ(node*2+1,mid+1,en,l,r);
        return max(lM,rM);
    }
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int q=queries.size();
        int mx=50005;
        tree.assign(4*(1+mx),0);
        set<int> obs;
        obs.insert(0),obs.insert(mx);
        vector<bool> ans;
        for(auto& x: queries){
            int type=x[0];
            if(type==1){
                int ob=x[1];
                auto it=obs.upper_bound(ob);
                int nxt=*it,prv=*prev(it);
                obs.insert(ob);
                upd(1,0,mx,ob,ob-prv);
                upd(1,0,mx,nxt,nxt-ob);
            }
            else{
                int lim=x[1],sz=x[2];
                auto it=obs.upper_bound(lim);
                int prv=*prev(it),last=lim-prv;
                int gapM=maxQ(1,0,mx,0,prv);
                if(max(gapM,last)>=sz)ans.push_back(true);
                else ans.push_back(false);
            }
        }
        return ans;
    }
};
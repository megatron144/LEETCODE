class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int c1=center[0],c2=center[1];
        int best=-1;
        vector<int> ans={-1,-1};
        for(auto &x:towers){
            int d=abs(x[0]-c1)+abs(x[1]-c2);
            if(d>radius)continue;
            if(x[2]>best || (x[2]==best && (ans[0]==-1 || x[0]<ans[0] || (x[0]==ans[0] && x[1]<ans[1])))){
                best=x[2];
                ans={x[0],x[1]};
            }
        }
        return ans;
    }
};
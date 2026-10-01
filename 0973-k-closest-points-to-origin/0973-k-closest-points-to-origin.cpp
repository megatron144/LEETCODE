class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,pair<int,int>>> v;
        for(auto& x: points){
            int r=x[0],c=x[1];
            int d=r*r+c*c;
            v.push_back({d,{r,c}});
        }
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        for(int i=0;i<k;i++)ans.push_back({v[i].second.first,v[i].second.second});
        return ans;
    }
};
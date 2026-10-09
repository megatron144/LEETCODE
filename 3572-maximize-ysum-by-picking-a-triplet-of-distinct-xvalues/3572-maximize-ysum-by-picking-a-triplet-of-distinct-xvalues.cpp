class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int,int> mp;
        int n=x.size();
        for(int i=0;i<n;i++){
            mp[x[i]]=max(mp[x[i]],y[i]);
        }
        if(mp.size()<3)return -1;
        vector<int> v;
        for(auto& x: mp)v.push_back(x.second);
        sort(v.begin(),v.end(),greater<int>());
        return v[0]+v[1]+v[2];
    }
};
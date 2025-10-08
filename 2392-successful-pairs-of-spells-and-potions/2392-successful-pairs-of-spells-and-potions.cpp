class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(auto x: spells){
            long long mn=(success+x-1)/x;
            int cnt=0;
            auto it=lower_bound(potions.begin(),potions.end(),mn);
            cnt=potions.end()-it;
            ans.push_back(cnt);
        }
        return ans;
    }
};
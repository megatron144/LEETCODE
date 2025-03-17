class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x: nums){
            mp[x]=abs(1-mp[x]);
        }
        for(auto x: mp){
            if(x.second)return false;
        }
        return true;
    }
};
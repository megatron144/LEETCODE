class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mini=*min_element(nums.begin(),nums.end());
        if(mini<k)return -1;
        bool flag=false;
        unordered_map<int,int> mp;
        for(auto x: nums){
            mp[x]++;
            if(x==k)flag=true;
        }
        if(flag)return mp.size()-1;
        return mp.size();
    }
};
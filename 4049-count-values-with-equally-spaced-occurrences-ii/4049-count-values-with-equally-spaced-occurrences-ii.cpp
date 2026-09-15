class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;++i)mp[nums[i]].push_back(i);
        for(auto& [val,v]: mp){
            int sz=v.size();
            if(sz<3)continue;
            int d=v[1]-v[0];
            for(int i=2;i<sz;++i)if(v[i]-v[i-1]!=d){goto there;}
            cnt++;
            there:
        }
        return cnt;
    }
};
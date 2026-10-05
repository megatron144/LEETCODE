class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,long long> prev,curr;
        long long cnt=0;
        for(auto& x: nums){
            curr.clear();
            curr[x]=1;
            for(auto& [val,f]: prev)curr[val&x]+=f;
            cnt+=curr[k];
            prev=curr;
        }
        return cnt;
    }
};
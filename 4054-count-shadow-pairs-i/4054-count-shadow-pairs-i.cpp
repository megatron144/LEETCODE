class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        long long cnt=0;
        vector<int> v;
        for(auto x: nums){
            while(!v.empty() && v.back()>x)v.pop_back();
            cnt+=lower_bound(v.begin(),v.end(),x)-v.begin();
            v.push_back(x);
        }
        return cnt;
    }
};
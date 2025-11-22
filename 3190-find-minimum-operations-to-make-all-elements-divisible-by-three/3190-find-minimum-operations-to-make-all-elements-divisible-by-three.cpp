class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        for(auto x: nums)cnt+=min(x%3,3-x%3);
        return cnt;
    }
};
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int maxi=-1,cnt=0;
        for(auto x: nums)
            if(maxi<=x)cnt++,maxi=x;
        return cnt;
    }
};
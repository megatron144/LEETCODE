class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        for(auto x: nums)if(x==1)cnt++;
        if(cnt)return n-cnt;
        for(int d=2; d<=n; d++){
            for(int l=0; l<=n-d; l++){
                int g=nums[l]=gcd(nums[l], nums[l+1]);
                if (g==1) return d+n-2;
            }
        }
        return -1;
    }
};
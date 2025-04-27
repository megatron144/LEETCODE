class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        for(int i=0;i<n-2;i++){
            int tmp=nums[i]+nums[i+2];
            tmp*=2;
            if(tmp==nums[i+1])cnt++;
        }
        return cnt;
    }
};
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();i++)v.push_back(i);
        if(v==nums)return 0;
        int k=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                k&=nums[i];
                if(k==0)return 0;
            }
        }
        return max(0,k);
    }
};
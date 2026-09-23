class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if(nums.size()==1)return (nums[0]==x)?1:-1;
        int n=nums.size(),j=0,mx=0,curr=0;
        int tar=accumulate(nums.begin(),nums.end(),0)-x;
        if(!tar)return n;
        if(tar<0)return -1;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            while(curr>tar)curr-=nums[j++];
            if(curr==tar)mx=max(mx,i-j+1);
        }
        return mx?n-mx:-1;
    }
};
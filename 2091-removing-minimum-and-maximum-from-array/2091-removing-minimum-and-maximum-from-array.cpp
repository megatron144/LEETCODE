class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        int a=0,b=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==mn)a=i;
            if(nums[i]==mx)b=i;
        }
        if(a<b)swap(a,b);
        return min({a+1,b+1+n-a,n-b});
    }
};
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        for(int i=0;i<(n/2-1);i++)nums.push_back(nums[i]);
        long long curr=0;
        int cnt=0;
        for(int i=0;i<n/2-1;i++)curr+=nums[i];
        for(int i=n/2-1;i<nums.size();i++){
            curr+=(long long)nums[i];
            cout<<curr<<" ";
            if(curr>(sum-curr))cnt++;
            curr-=(long long)nums[i-n/2+1];
        }
        return cnt;
    }
};
class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int mx=1,n=nums.size();
        for(int i=0;i<n;i++){
            int rem=nums[i]%k;
            int j=i;
            while(j<n && nums[j]%k==rem)j++;
            int cyc=k/gcd(rem,k);
            mx=max(mx,1+(j-i-1)/cyc*cyc);
            i=j-1;
        }
        return mx;
    }
};
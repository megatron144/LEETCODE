class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> p(n,0),s(n+1,0);
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(nums[i])cnt++;
            else p[i]=cnt,cnt=0;
            ans=max(ans,cnt);
        }
        ans=max(ans,cnt);
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i])cnt++;
            else s[i]=cnt,cnt=0;
        }
        for(int i=0;i<n;i++)if(nums[i]==0)ans=max(ans,p[i]+s[i]);
        return (ans==n)?--ans:ans;
    }
};
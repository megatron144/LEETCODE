class Solution {
#define f(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size(),cnt=0;
        f(i,0,n-1){
            if(nums[i]==0){
                cnt++;
                continue;
            }
            if(nums[i]!=nums[i+1]){
                ans.pb(nums[i]);
                continue;
            }
            if(nums[i]==nums[i+1])
            ans.pb(nums[i]*2);
            nums[i+1]=0;
        }
        if(nums[n-1]==0)cnt++;
        else ans.pb(nums[n-1]);
        while(cnt--)ans.pb(0);
        return ans;
    }
};
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int mod=1e9+7;
        int n=nums.size();
        vector<int> dp(n+1),pre(n+1);
        dp[0]=1;pre[0]=1;
        deque<int> minq,maxq;
        int L=0;
        for(int i=0;i<n;++i){
            while(!minq.empty() && nums[i]<nums[minq.back()])minq.pop_back();
            minq.push_back(i);
            while(!maxq.empty() && nums[i]>nums[maxq.back()])maxq.pop_back();
            maxq.push_back(i);
            while(nums[maxq.front()]-nums[minq.front()]>k){
                if(maxq.front()==L)maxq.pop_front();
                if(minq.front()==L)minq.pop_front();
                ++L;
            }
            long long ways=pre[i] - (L>0?pre[L-1]:0);
            ways=(ways%mod+mod)%mod;
            dp[i+1]=ways;
            pre[i+1]=(pre[i]+dp[i+1])%mod;
        }
        return dp[n];
    }
};
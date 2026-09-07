class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        int n=nums.size();
        vector<int> dp(sum+1,100);
        dp[0]=0;
        for(auto& x: nums){
            vector<int> v,mn(sum+1,100);
            int curr=x,cnt=0;
            while(curr<=sum){
                mn[curr]=min(mn[curr],cnt);
                v.push_back(curr);
                cnt++;
                curr<<=1;
            }
            curr=x,cnt=0;
            while(curr>0){
                if(curr<=sum){
                    mn[curr]=min(mn[curr],cnt);
                    if(find(v.begin(),v.end(),curr)==v.end())v.push_back(curr);
                }
                cnt++;
                curr>>=1;
            }
            vector<int> tmp=dp;
            for(int i=0;i<=sum;i++){
                if(dp[i]==100)continue;
                for(auto& j : v){
                    if(i+j>sum)continue;
                    if(mn[j]==100)continue;
                    tmp[i+j]=min(tmp[i+j],dp[i]+mn[j]);
                }
            }
            dp=tmp;
        }
        if(dp[sum]==100)return -1;
        return dp[sum];
    }
};
class Solution {
public:
    int zigZagArrays(int n,int l,int r) {
        int MOD=1e9+7;
        r-=l;
        vector<int> dp(r+1,1);
        for(int i=1;i<n;i++){
            int pre=0,pre2=0;
            for(int v=0;v<=r;v++){
                pre2=pre+dp[v];
                dp[v]=pre;
                pre=pre2%MOD;
            }
            reverse(dp.begin(),dp.end());
        }
        int cnt=0;
        for(auto& x:dp)cnt=(cnt+x)%MOD;
        return cnt*2%MOD;
    }
};
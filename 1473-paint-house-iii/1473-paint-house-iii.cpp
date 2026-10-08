class Solution {
    int dp[105][105][25];
    int M,N;
    int solve(int idx,int target, int last,auto& houses,auto& cost) {
        if(target<0)return 1e9;
        if(idx==M)return target==0?0:1e9;
        if(dp[idx][target][last+1]!=-1)return dp[idx][target][last + 1];
        long long mn=1e9;
        if(houses[idx]){
            int color=houses[idx];
            int new_target=target-(color!=last?1:0);
            mn=solve(idx+1,new_target,color,houses,cost);
        } 
        else{
            for(int i=1;i<=N;i++) {
                int new_target=target-(i!=last?1:0);
                long long curr=cost[idx][i-1]+solve(idx+1,new_target,i,houses,cost);
                mn=min(mn,curr);
            }
        }
        return dp[idx][target][last+1]=mn;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        M=m,N=n;
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,target,-1,houses,cost);
        return ans>=1e9?-1:ans;
    }
};
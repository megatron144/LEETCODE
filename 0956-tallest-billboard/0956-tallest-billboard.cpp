class Solution {
int dp[20][10001];
int sum;
private:
    int solve(int idx,int d,auto& rods){
        //if(d>sum/2)return -1e9;
        if(idx==rods.size()){
            return (d==0)?0:-1e9;
        }
        if(dp[idx][d+5000]!=-1)return dp[idx][d+5000];
        return dp[idx][d+5000]=max(
            solve(idx+1,d,rods),
            rods[idx]+max(solve(idx+1,d-rods[idx],rods),
                        solve(idx+1,d+rods[idx],rods))
        );
    }
public:
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        sum=accumulate(rods.begin(),rods.end(),0);
        int ans=solve(0,0,rods)/2; 
        return ans;
    }
};
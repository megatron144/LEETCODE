class Solution {
vector<long long> dp;
int n;
private:
    long long f(vector<vector<int>>& q,int i){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        long long take=0,skip=0;
        take=q[i][0]+f(q,i+q[i][1]+1);
        skip=f(q,i+1);
        return dp[i]=max(take,skip);
    }
public:
    long long mostPoints(vector<vector<int>>& q) {
        n=q.size();
        dp.resize(n,-1);
        dp[n-1]=q[n-1][0];
        return f(q,0);
    }
};
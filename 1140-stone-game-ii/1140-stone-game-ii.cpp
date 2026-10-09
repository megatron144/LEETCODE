class Solution {
int dp[101][101][2];
int n;
private:
    int check(int idx,int m,int a,auto& piles){
        if(idx>=n)return 0;
        auto& x=dp[idx][m][a];
        if(x!=-1)return x;
        x=a?INT_MIN:INT_MAX;
        int sum=0;
        for(int i=1;i<=min(2*m,n-idx);i++){
            sum+=piles[idx+i-1];
            if(a)x=max(x,sum+check(idx+i,max(m,i),a^1,piles));
            else x=min(x,check(idx+i,max(m,i),a^1,piles));
        }
        return x;
    }
public:
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        return check(0,1,1,piles);
    }
};
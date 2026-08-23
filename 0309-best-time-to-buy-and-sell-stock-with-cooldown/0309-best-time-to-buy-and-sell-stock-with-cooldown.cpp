class Solution {
vector<vector<int>> dp;
int n;
private:
    int maxP(vector<int>& prices,int i,int buy){
        if(i>=n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy)return dp[i][buy]=max(maxP(prices,i+1,buy),
                                maxP(prices,i+1,buy^1)-prices[i]);
        else return dp[i][buy]=max(maxP(prices,i+1,buy),
                                maxP(prices,i+2,buy^1)+prices[i]);
    }
public:
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.resize(n,vector<int> (2,-1));
        return maxP(prices,0,1);
    }
};
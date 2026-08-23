class Solution {
vector<vector<vector<int>>> dp;
int n;
private:
    int maxP(vector<int>& prices,int i,int buy,int cnt){
        if(i==n || !cnt)return 0;
        if(dp[i][buy][cnt-1]!=-1)return dp[i][buy][cnt-1];
        if(buy)return dp[i][buy][cnt-1]=max(maxP(prices,i+1,buy,cnt),
                                maxP(prices,i+1,buy^1,cnt)-prices[i]);
        else return dp[i][buy][cnt-1]=max(maxP(prices,i+1,buy,cnt),
                                maxP(prices,i+1,buy^1,cnt-1)+prices[i]);
    }
public:
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        //dp[idx][buy][can]
        dp.resize(n,vector<vector<int>> (2,vector<int> (2,-1)));
        return maxP(prices,0,1,2);
    }
};
class Solution {
vector<long long>dp;
int n,K;
private:
    inline int get_idx(int i, int id, int cnt) {
        return (i * 3 + id) * (K + 1) + cnt;
    }
    long long maxP(auto& prices,int i,int id,int cnt){
        if(i==n || !cnt)return !id?0:-1e14;
        int idx=get_idx(i,id,cnt);
        if(dp[idx]!=-1)return dp[idx];
        if(!id){
            return dp[idx]=max({maxP(prices,i+1,id,cnt),
                                    maxP(prices,i+1,1,cnt)-(long long)prices[i],
                                    maxP(prices,i+1,2,cnt)+(long long)prices[i]});
        }
        if(id==1){
            return dp[idx]=max({maxP(prices,i+1,id,cnt),
                                    maxP(prices,i+1,0,cnt-1)+(long long)prices[i]});
        }
        return dp[idx]=max({maxP(prices,i+1,id,cnt),
                                    maxP(prices,i+1,0,cnt-1)-(long long)prices[i]});
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        n=prices.size();
        bool all_same = true;
        for (int i = 1; i < n; ++i) {
            if (prices[i] != prices[0]) {
                all_same = false;
                break;
            }
        }
        if (all_same) return 0;
        //dp[idx][id][can]
        //normal: 0->buy 1->sell
        //short sell: 0->sell 2->buy
        K=k;
        dp.assign(n*3*(k+1),-1);
        return maxP(prices,0,0,k);
    }
};
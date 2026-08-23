class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=1,n=prices.size();
        int maxi=0,buy=prices[0];
        while(i<n){
            if(prices[i]<buy)buy=prices[i];
            else{
                if(prices[i]-buy>maxi)maxi=prices[i]-buy;
            }
            i++;
        }
        return maxi;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,n=prices.size();
        for(int i=0;i<n;i++){
            int j=i+1;
            while(j<n && prices[j]>prices[j-1])j++;
            ans+=prices[j-1]-prices[i];
            i=j-1;
        }
        return ans;
    }
};
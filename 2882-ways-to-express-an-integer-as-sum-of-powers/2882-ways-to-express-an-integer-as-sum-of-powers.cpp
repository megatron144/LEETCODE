class Solution {
private:
    int m=1000000007;
public:
    int numberOfWays(int n, int x) {
        vector<int> powers;
        for(int i=1;;i++){
            int val=1;
            for(int j=0;j<x;j++){
                val*=i;
                if(val>n)break;
            }
            if(val>n)break;
            powers.push_back((int)val);
        }
        vector<int> dp(n+1);
        dp[0]=1;
        for(auto x:powers){
            for(int s=n;s>=x;s--)
                dp[s]=(dp[s]%m+dp[s-x]%m)%m;
        }
        return dp[n];
    }
};
class Solution {
public:
    int distinctSubseqII(string s) {
        int curr=0,M=1e9+7;
        vector<int> dp(26,0);
        for(auto& x: s){
            x-='a';
            int newS=(curr-dp[x]+M)%M;
            dp[x]=1+curr;
            curr=(dp[x]+newS)%M;
        }
        return curr;
    }
};
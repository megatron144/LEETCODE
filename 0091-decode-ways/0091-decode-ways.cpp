class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        if(s[0]!='0')dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            int singleDig=s[i-1]-'0';//char s[i-1]="8" , singleDig = 8
            int doubleDig=stoi(s.substr(i-2,2));
            if(singleDig!=0)dp[i]+=dp[i-1];
            if(doubleDig>=10 && doubleDig<=26)dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};
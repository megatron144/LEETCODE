class Solution {
private:
    static bool cmp(string& a,string& b){return a.size()<b.size();}
    bool check(string a,string b){
        if(b.size()-a.size()!=1)return false;
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j])i++;
            j++;
        }
        return i==a.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int> dp(n,1);
        int mx=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]+1>dp[i] && check(words[j],words[i]))dp[i]=1+dp[j],mx=max(mx,dp[i]);
            }
        }
        return mx;
    }
};
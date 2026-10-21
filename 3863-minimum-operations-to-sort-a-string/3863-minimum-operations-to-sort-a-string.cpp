class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(n==1)return 0;
        if(n==2)return (s[0]<=s[1])?0:-1;
        char mn=s[0],mx=s[0];
        bool flg=true;
        for(int i=1;i<n;i++){
            mn=min(mn,s[i]),mx=max(mx,s[i]);
            if(s[i-1]>s[i])flg=false;
        }
        if(flg)return 0;
        if(mn==s[0] || mx==s[n-1])return 1;
        for(int i=1;i<n-1;i++)if(s[i]==mn || s[i]==mx)return 2;
        return 3;
    }
};
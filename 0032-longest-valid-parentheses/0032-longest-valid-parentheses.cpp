class Solution {
public:
    int longestValidParentheses(string s) {
        int o1,o2,c1,c2;
        o1=o2=c1=c2=0;
        int cnt=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==')')c1++;
            else o1++;
            if(o1==c1)cnt=max(cnt,o1+c1);
            if(o1<c1)o1=c1=0;
            if(s[n-i-1]==')')c2++;
            else o2++;
            if(o2==c2)cnt=max(cnt,o2+c2);
            if(o2>c2)o2=c2=0;
        }
        return cnt;
    }
};
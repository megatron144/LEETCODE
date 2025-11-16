class Solution {
public:
    int numSub(string s) {
        int m=1e9+7;
        int cnt=0,n=s.size(),len=0,j;
        for(int i=0;i<n;i++){
            if(s[i]=='0')continue;
            len=0,j=i;
            while(j<n && s[j]=='1')j++,len++;
            long long add=(1LL* len%m * (len+1)%m)%m;
            add>>=1;
            cnt+=(int)add;
            i=j-1;
        }
        return cnt;
    }
};
class Solution {
public:
    bool sumGame(string num) {
        int c1=0,c2=0,n=num.size();
        int s1=0,s2=0;
        for(int i=0;i<n;++i){
            if(i<n/2){
                if(num[i]=='?')c1++;
                else s1+=(int)(num[i]-'0');
            }
            else{
                if(num[i]=='?')c2++;
                else s2+=(int)(num[i]-'0');
            }
        }
        if(c1==c2)return s1!=s2;
        if((c1+c2)&1)return true;
        return 2*(s1-s2)!=9*(c2-c1);
    }
};
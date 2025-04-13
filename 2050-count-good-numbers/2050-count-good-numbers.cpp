class Solution {
long long MOD=1e9+7;
private:
    long long power(long long x,long long y) {
        long long res = 1;
        while(y>0){
            if(y&1)res=res*x%MOD;
            x=x*x%MOD;
            y>>=1;
        }
        return res;
    }
public:
    int countGoodNumbers(long long n) {
        long long c1=n/2,c2=n/2;
        if(n&1)c1++;
        long long even=power(5,c1),odd=power(4,c2);
        return int(((even%MOD) * (odd%MOD))%MOD);
    }
};
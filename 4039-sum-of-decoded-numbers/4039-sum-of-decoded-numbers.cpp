class Solution {
private:
    long long mod=1e9+7;
    long long powerX(long long x,long long y){
        if(y==0)return 1LL;
        if(y==1)return x;
        long long res=powerX(x,y/2)%mod;
        if(y&1)return (((res*x)%mod)*res)%mod;
        return (res*res)%mod;
    }
public:
    int sumDecoded(vector<long long>& nums) {
        long long cnt=0;
        for(auto xx: nums){
            long long w=xx%10,d=xx/10;
            string ds=to_string(d);
            int rem=ds.length()-w;
            string xs=ds.substr(0,w),ys=ds.substr(w,rem);
            int x=stoi(xs),y=stoi(ys);
            long long res=powerX(x,y);
            cnt=(cnt+res)%mod;
        }
        return (int)cnt;
    }
};
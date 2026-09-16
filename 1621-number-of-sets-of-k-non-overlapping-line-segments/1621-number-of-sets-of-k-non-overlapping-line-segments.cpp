class Solution {
int M=1e9+7;
private:
    int modP(int x,int y){
        if(!y)return 1;
        if(y==1)return x;
        int res=modP(x,y/2);
        if(y&1)return (long long)res*res%M*x%M;
        return (long long)res*res%M;
    }
public:
    int numberOfSets(int n, int k) {
        int num=n+k-1,d=2*k;
        long long u=1,l=1;
        for(int i=1;i<=2*k;i++){
            u=u*num%M;
            num--;
            l=l*d%M;
            d--;
        }
        int ans=u*modP(l,M-2)%M;
        return ans;
    }
};
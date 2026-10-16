#include <vector>

class Solution {
private:
    int MOD=1e9+7;
    vector<vector<long long>> multiply(auto& A,auto& B){
        int r=A.size();
        int c1=A[0].size();
        int c2=B[0].size();
        vector<vector<long long>> C(r,vector<long long>(c2,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c2;j++){
                long long sum=0;
                for(int k=0;k<c1;k++)sum=(sum+A[i][k]*B[k][j])%MOD;
                C[i][j]=sum;
            }
        }
        return C;
    }
    vector<vector<long long>> power(auto& base,long long exp) {
        int n=base.size();
        vector<vector<long long>> res(n,vector<long long>(n,0));
        for(int i=0;i<n;i++)res[i][i]=1;
        vector<vector<long long>> b=base;
        while(exp){
            if(exp&1)res=multiply(res,b);
            b=multiply(b,b);
            exp>>=1;
        }
        return res;
    }
public:
    int zigZagArrays(int n, int l, int r) {
        int k=r-l+1;
        if(n==1)return k;
        int sz=2*k;
        vector<vector<long long>> initial(sz,vector<long long>(1,0));
        for(int i=1;i<=k;i++)initial[i-1][0]=k-i,initial[k+i-1][0]=i-1;
        vector<vector<long long>> T(sz,vector<long long>(sz,0));
        for(int i=1;i<=k;i++){
            for(int j=1;j<i;j++)T[k+i-1][j-1]=1;
            for(int j=i+1;j<=k;j++)T[i-1][k+j-1]=1;
        }
        vector<vector<long long>> Tn=power(T,n-2);
        vector<vector<long long>> ans=multiply(Tn,initial);
        long long cnt=0;
        for(int i=0;i<sz;i++)cnt=(cnt+ans[i][0])%MOD;
        return (int)cnt;
    }
};
#define vi vector<int>
class Solution {
int MAXN;
vector<bool> isPrime;
vi primes;
private:
    void sieve(){
        isPrime.resize(MAXN,true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2;i<MAXN;i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for(int j=i*2;j<MAXN;j+=i) {
                    isPrime[j]=false;
                }
            }
        }
    }
public:
    vector<int> maxPrimeSubset(int n, int s) {
        MAXN=n+1;
        sieve();
        int m=primes.size();
        vector<vector<int>> dp(m+1,vector<int> (s+1,1e6));
        dp[m][0]=0;
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<=s;j++){
                auto& x=dp[i][j];
                x=dp[i+1][j];
                if(j>=primes[i] && dp[i+1][j-primes[i]]!=1e6)x=min(x,dp[i+1][j-primes[i]]+1);
            }
        }
        int mx=0;
        for(int i=s;i>=1;i--)if(dp[0][i]!=1e6){mx=i;break;}
        if(!mx)return {};
        vi v;
        int i=0,rem=dp[0][mx];
        while(rem){
            for(int j=i;j<m;j++) {
                if(primes[j]<=mx && dp[j+1][mx-primes[j]]==rem-1){
                    v.push_back(primes[j]);
                    mx-=primes[j];
                    rem--;
                    i=j+1;
                    break;
                }
            }
        }
        return v;
    }
};
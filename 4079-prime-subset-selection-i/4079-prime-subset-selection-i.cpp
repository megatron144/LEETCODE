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
    vector<int> maxPrimes(int n, int s) {
        MAXN=n+1;
        sieve();
        int m=primes.size();
        vi v;
        for(auto& x: primes){
            s-=x;
            if(s>=0)v.push_back(x);
            else break;
        }
        return v;
    }
};
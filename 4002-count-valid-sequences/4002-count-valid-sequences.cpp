#define vi vector<ll> // Changed vi to use long long vector
#define ll long long
const ll MOD = 1000000007LL;
#define f(i,a,b) for(ll i=a;i<b;i++)

class Solution {
    ll MAXN;
    vi fact, inv; 

    ll power(ll base, ll exp, ll mod) {
        ll res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    void preprocess() {
        fact.resize(MAXN + 1, 1);
        inv.resize(MAXN + 1, 1);
        fact[0] = 1;
        f(i, 1, MAXN + 1)
            fact[i] = i * fact[i - 1] % MOD;
        
        inv[MAXN] = power(fact[MAXN], MOD - 2, MOD);
        for (ll i = MAXN - 1; i >= 0; i--)
            inv[i] = inv[i + 1] * (i + 1) % MOD; // Safe from overflow now
    }

    ll ncr(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
    }

public:
    int countValidSequences(int n, int k) {
        MAXN = n + 5;
        preprocess();
        
        ll tot = ncr(n - 1, k - 1);
        if ((n - k) & 1) return tot;
        
        ll odd = ncr((n - k) / 2 + k - 1, k - 1);
        return (int)((tot - odd + MOD) % MOD);
    }
};
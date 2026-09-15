class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // int cnt=0;
        // long long val=0;
        // priority_queue<long long,vector<long long>,greater<long long>> pq;
        // pq.push(1);
        // int i=0;
        // while(!pq.empty() && cnt!=n){
        //     long long mx=pq.top();
        //     val=mx;
        //     for(int j=0;j<primes.size();j++){
        //        pq.push(mx*primes[j]);
        //     }
        //     while(!pq.empty() && mx==pq.top()){
        //        pq.pop();
        //     }
        //     cnt++;
        // }
        // return val;
        vector<long long> dp(n);
        int k=primes.size();
        vector<int> idx(k,0);
        dp[0]=1;
        for(int i=1;i<n;++i){
            long long mn=INT_MAX;
            for(int j=0;j<k;++j)mn=min(mn,dp[idx[j]]*primes[j]);
            dp[i]=mn;
            for(int j=0;j<k;++j)if(mn==(dp[idx[j]]*primes[j]))idx[j]++;
        }
        return dp[n-1];
    }
};
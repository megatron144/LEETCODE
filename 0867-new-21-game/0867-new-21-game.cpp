class Solution {
// private:
//     vector<double> dp;
//     int M,K,N;
//     double f(int sum){
//         if(sum>N)return 0.0;
//         if(sum>=K)return 1.0;
//         if(dp[sum]!=-1.0)return dp[sum];
//         double prob=0.0;
//         for(int i=1;i<=M;i++){
//             prob+=((1.0/M)*f(sum+i));
//         }
//         return dp[sum]=prob;
//     }
public:
    double new21Game(int n, int k, int maxPts) {
        // dp.resize(n+1,-1.0);
        // M=maxPts;
        // K=k;
        // N=n;
        // return f(0);
        if(k==0 || n>=k+maxPts-1) return 1.0;

        vector<double> dp(n+1, 0.0);
        dp[0] = 1.0;
        double windowSum = 1.0; // sum of last maxPts dp values
        double ans = 0.0;
        for(int i=1;i<=n;i++){
            dp[i] = windowSum / maxPts;
            if(i < k) windowSum += dp[i];
            else ans += dp[i];
            if(i-maxPts >= 0) windowSum -= dp[i-maxPts];
        }
        return ans;
    }
};
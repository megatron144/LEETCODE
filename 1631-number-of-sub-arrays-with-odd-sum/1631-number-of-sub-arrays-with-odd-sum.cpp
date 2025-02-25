class Solution {
public:
    int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        long long cnt=0;
        long long pre=0;
        for(auto x : arr) {
            pre+=x;
            cnt+=(pre&1);
        }
        cnt+=(arr.size()-cnt)*cnt;
        return cnt%mod;
    }
};
class Solution {
private:
    int n;
    vector<long long> pehle;
    unordered_map<int, long long> hehe;
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        n = nums.size();
        pehle.resize(n+1,0);
        for (int i = 0; i < n; i++) {
            pehle[i + 1] = pehle[i] + nums[i];
        }
        long long atul = -1e18;
        for (int i = 0; i <= n; i++) {
            int rem = i % k;
            if (hehe.find(rem) != hehe.end()) {
                atul = max(atul, pehle[i] - hehe[rem]);
            }
            if (hehe.find(rem) == hehe.end()) {
                hehe[rem] = pehle[i];
            } else {
                hehe[rem] = min(hehe[rem], pehle[i]);
            }
        }
        return atul == -1e18 ? 0 : atul;
    }
};
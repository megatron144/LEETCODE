class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        int ans = 0;
        for (int b = 30; b >= 0; b--) {
            int target = ans | (1 << b);
            vector<long long> costs;
            for (int x : nums) {
                long long current_val = x;
                long long current_cost = 0;
                for (int i = 30; i >= b; i--) {
                    if ((target >> i) & 1) {
                        if (!((current_val >> i) & 1)) {
                            long long new_val = ((current_val >> i) | 1LL) << i;
                            current_cost += (new_val - current_val);
                            current_val = new_val;
                        }
                    }
                }
                costs.push_back(current_cost);
            }
            sort(costs.begin(), costs.end());
            long long sum = 0;
            for (int i = 0; i < m; i++) sum += costs[i];
            if (sum <= k) {
                ans = target;
            }
        }
        return ans;
    }
};
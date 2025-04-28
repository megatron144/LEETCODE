class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int j = 0;
        long long sum = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum * (i - j + 1) >= k) {
                sum -= nums[j];
                j++;
            }
            cnt += (i - j + 1);
        }
        return cnt;
    }
};
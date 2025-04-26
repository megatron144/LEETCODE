class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long int count = 0;
        int problem = -1, minIndex = -1, maxIndex = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK)
                problem = i;
            if (nums[i] == minK)
                minIndex = i;
            if (nums[i] == maxK)
                maxIndex = i;
            count += max(0, min(minIndex, maxIndex) - problem);
        }
        return count;
    }
};
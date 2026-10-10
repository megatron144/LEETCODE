class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=1,left=0,n=nums.size();
        deque<int> mx,mn;
        for(int right=0;right<n;right++) {
            while(!mx.empty() && nums[mx.back()]<nums[right])mx.pop_back();
            while(!mn.empty() && nums[mn.back()]>nums[right])mn.pop_back();
            mx.push_back(right);
            mn.push_back(right);
            while(nums[mx.front()]-nums[mn.front()]>limit) {
                if(mx.front()==left)mx.pop_front();
                if(mn.front()==left)mn.pop_front();
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto& x: nums)mp[x]++;
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for(auto& [val, freq] : mp)buckets[freq].push_back(val);
        for(int freq=n;freq>=1;freq--) {
            for(auto& val:buckets[freq]) {
                ans.push_back(val);
                if(ans.size()==k)goto there;
            }
        }
        there:
        return ans;
    }
};
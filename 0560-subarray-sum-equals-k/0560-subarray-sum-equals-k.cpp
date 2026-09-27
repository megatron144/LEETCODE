class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        //if(!k)return 0;
        unordered_map<int,int> pre;
        int curr=0,cnt=0;
        pre[curr]=1;
        for(auto& x: nums){
            curr+=x;
            if(pre.count(curr-k))cnt+=pre[curr-k];
            pre[curr]++;
        }
        return cnt;
    }
};
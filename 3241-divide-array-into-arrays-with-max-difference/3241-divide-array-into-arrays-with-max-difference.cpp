class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        int len=nums.size();
        for(int i=0;i<len;i++){
            tmp.clear();
            if((nums[i+2]-nums[i])<=k){
                tmp.push_back(nums[i]);
                tmp.push_back(nums[++i]);
                tmp.push_back(nums[++i]);
                ans.push_back(tmp);
            }
            else{
                ans.clear();
                return ans;
            }
        }
        return ans;
    }
};
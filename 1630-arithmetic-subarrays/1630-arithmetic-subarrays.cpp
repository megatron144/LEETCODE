class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for(int i=0;i<l.size();++i) {
            vector<int> n(begin(nums)+l[i],begin(nums)+r[i]+1);
            sort(begin(n),end(n));
            int j=2;
            for(;j<n.size();++j)if(n[j]-n[j-1]!=n[1]-n[0])break;
            res.push_back(j==n.size());
        }
        return res;
    }
};
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(auto x: nums){
            if(x%2==0)ans.push_back(-1);
            else{
                bitset<12> b(x);
                for (int i = 0; i<12; i++) {
                    if (b[i + 1] == 0) {
                        b[i] = 0;
                        ans.push_back((int)b.to_ullong()); 
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
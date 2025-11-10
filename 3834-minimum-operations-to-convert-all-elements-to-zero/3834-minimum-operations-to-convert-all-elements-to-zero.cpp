class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> v;
        nums.push_back(0);
        int cnt=0;
        for(auto x: nums){
            while(!v.empty() && v.back()>x){
                int val=v.back();
                while(!v.empty() && v.back()==val)
                    v.pop_back();
                cnt++;
            }
            if(v.empty() || (v.back()<x))v.push_back(x);
        }
        return cnt;
    }
};
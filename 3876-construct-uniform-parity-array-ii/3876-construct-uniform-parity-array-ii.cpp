class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        int n=nums1.size();
        int par=(nums1[0]&1)?1:0;
        for(int i=0;i<n;i++){
            if(par==(nums1[i]&1))continue;
            if(par!=((nums1[i]-nums1[0])&1))return false;
        }
        return true;
    }
};
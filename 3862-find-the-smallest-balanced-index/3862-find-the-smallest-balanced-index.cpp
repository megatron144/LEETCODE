class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long l=0,r=1;
        int j=nums.size()-1;
        for(int i=0;i<nums.size();++i){
            while(j>i && l>=r && (l/r)+1>=nums[j]){
                r*=nums[j];
                j--;
            }
            if(j==i && l==r)return i;
            l+=nums[i];
        }
        return -1;
    }
};
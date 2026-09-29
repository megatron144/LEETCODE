class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        unordered_map<int,int> mp1,mp2;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp1[nums[i]^nums[j]]=1;
            }
        }
        for(auto& x: nums)for(auto& y: mp1)mp2[y.first^x]=1;
        return mp2.size();
    }
};
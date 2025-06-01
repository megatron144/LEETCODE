class Solution {
private:
    bool f(long long target,int i,vector<int>& nums){
        if(1==target)return true;
        if(i==nums.size())return false;
        bool take=false;
        if(target%nums[i]==0)take=f(target/(long long)nums[i],i+1,nums);
        return take|f(target,i+1,nums);
    }
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        __int128 prod=1;
        __int128 t=((__int128)target)*target;
        for(auto x : nums){
            prod*=x;
            if(prod>t)
                return false;
        }
        if(prod!=t) {
            return false;
        }
        int n=nums.size();
        return f(target,0,nums);
    }
};
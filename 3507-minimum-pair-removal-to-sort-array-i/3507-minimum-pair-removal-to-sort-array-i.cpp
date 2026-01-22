class Solution {
// #define int long long
#define f(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define vi vector<int>
#define all(v) v.begin(),v.end()
private:
    bool opp(vi nums){
        f(i,1,nums.size()){
            if(nums[i]<nums[i-1]) return false;
        }
        return true;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops=0;
        while(!opp(nums) && nums.size()>=2){
            int idx=0,tar=1e8;
            f(i,0,nums.size()-1){
                int curr=nums[i]+nums[i+1];
                if(curr<tar){
                    tar=curr;
                    idx=i;
                }
            }
            nums[idx]=tar;
            nums.erase(nums.begin()+idx+1);
            ops++;
        }
        return ops;
    }
};
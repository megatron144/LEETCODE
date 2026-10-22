class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n && nums[i]!=0)i++;
        for(int j=0;j<n;j++){
            if(j!=nums[(i+j)%n]){
                break;
            }
            else if(j==n-1)return min(i,n-i+2);
        }
        i=0;
        while(i<n && nums[i]!=n-1)i++;
        for(int j=0;j<n;j++){
            if(n-1-j!=nums[(j+i)%n])return -1;
            else if(j==n-1)return min(1+n-i,i+1);
        }
        return -1;
    }
};
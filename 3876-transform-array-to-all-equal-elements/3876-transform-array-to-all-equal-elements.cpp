class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n=nums.size();
        int one=count(nums.begin(),nums.end(),1),neg=n-one;
        if(one==0 || neg==0)return true;
        if((one&1) && (neg&1))return false;
        int m=1e8,M=1e8;
        if(!(neg&1)){
            int moves=0;
            for(int i=0;i<n;i++){
                if(nums[i]==1)continue;
                int j=i+1;
                while(j<n && nums[j]==1)j++;
                moves+=j-i;
                i=j+1;
                while(i<n && nums[i]==1)i++;
                i--;
            }
            m=moves;
        }
        if(!(one&1)){
            int moves=0;
            for(int i=0;i<n;i++){
                if(nums[i]==-1)continue;
                int j=i+1;
                while(j<n && nums[j]==-1)j++;
                moves+=j-i;
                i=j+1;
                while(i<n && nums[i]==-1)i++;
                i--;
            }
            M=moves;
        }
        cout<<m<<" "<<M<<endl;
        return min(m,M)<=k;
    }
};
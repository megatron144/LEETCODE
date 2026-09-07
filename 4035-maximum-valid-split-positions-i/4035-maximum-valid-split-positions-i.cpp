class Solution {
private:
    int cntMx(vector<int> v){
        int n=v.size();
        vector<int> pre,suff;
        int curr=0;
        for(auto x: v)curr=gcd(curr,x),pre.push_back(curr);
        curr=0;
        for(int i=n-1;i>=0;i--)curr=gcd(curr,v[i]),suff.push_back(curr);
        reverse(suff.begin(),suff.end());
        int cnt=0;
        for(int i=0;i<n-1;i++)if(pre[i]==suff[i+1])cnt++;
        return cnt;
    }
public:
    int maxValidSplits(vector<int>& nums) {
        int mx=0,n=nums.size();
        mx=max(mx,cntMx(nums));
        for(int i=0;i<n;i++){
            vector<int> tmp;
            for(int j=0;j<n;j++)if(j!=i)tmp.push_back(nums[j]);
            mx=max(mx,cntMx(tmp));
        }
        return mx;
    }
};
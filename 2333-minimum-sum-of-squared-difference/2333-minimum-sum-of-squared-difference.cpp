class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> v;
        int n=nums1.size(),mx=0;
        long long sum=0LL;
        for(int i=0;i<n;i++){
            int d=abs(nums1[i]-nums2[i]);
            mx=max(mx,d);
            v.push_back(d);
            sum+=(long long)d;
        }
        long long tot=k1+k2,ans=0;
        if(sum<=tot)return 0LL;
        vector<int> f(mx+1,0);
        for(auto& x: v)f[x]++;
        for(int i=mx;i>0;i--){
            if(!f[i])continue;
            if(tot>=f[i]){
                f[i-1]+=f[i];
                tot-=f[i];
                f[i]=0;
            }
            else{
                f[i-1]+=tot;
                f[i]-=tot;
                tot=0;
            }
            ans+=(long long)f[i]*i*i;
        }
        return ans;
    }
};
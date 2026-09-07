class Solution {
private:
    
    int cntMx(vector<int>& pre,vector<int>& suff,vector<int>& v,int idx){
        int n=v.size();
        pre.assign(n,0);
        suff.assign(n,0);
        for(int i=0;i<n;i++){
            if(i==idx)pre[i]=i?pre[i-1]:0;
            else pre[i]=gcd(i?pre[i-1]:0,v[i]);
        }
        for(int i=n-1;i>=0;i--){
            if(i==idx)suff[i]=(i==n-1)?0:suff[i+1];
            else suff[i]=gcd((i==n-1)?0:suff[i+1],v[i]);
        }
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(i==idx)continue;
            if(pre[i]==suff[i+1])cnt++;
        }
        return cnt;
    }
public:
    int maxValidSplits(vector<int>& nums) {
        int mx=0,n=nums.size();
        int curr=0;
        vector<int> pre;
        for(auto x: nums)curr=gcd(curr,x),pre.push_back(curr);
        vector<int> p,s;
        mx=max(mx,cntMx(p,s,nums,-1));
        for(int i=0;i<n;i++){
            if(i && pre[i]==pre[i-1])continue;
            int idx=i;
            p.clear();s.clear();
            mx=max(mx,cntMx(p,s,nums,idx));
        }
        return mx;
    }
};
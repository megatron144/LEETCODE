class Solution {
public:
    int alternatingXOR(vector<int>& nums, int t1, int t2) {
        int xo=0,m=1e9+7;
        for(auto x: nums)xo^=x;
        if(xo!=0 && xo!=t1 && xo!=(t1^t2) && xo!=t2)return 0;
        xo=0;
        unordered_map<int,int> mp1,mp2;
        int cnt1=0,cnt2=0;
        mp2[0]=1;
        for(auto& x: nums){
            xo^=x;
            int a=xo^t1,b=xo^t2;
            cnt1=mp2.count(a)?mp2[a]:0;
            cnt2=mp1.count(b)?mp1[b]:0;
            mp1[xo]=(mp1[xo]+cnt1)%m;
            mp2[xo]=(mp2[xo]+cnt2)%m;
        }
        return (cnt1+cnt2)%m;
    }
};
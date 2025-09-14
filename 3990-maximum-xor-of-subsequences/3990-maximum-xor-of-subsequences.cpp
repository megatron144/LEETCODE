struct LinearBasis {
    static const int LOG = 31;
    int basis[LOG+1];
    LinearBasis(){ fill(basis,basis+LOG+1,0); }
    void insert(int x){
        for(int i=LOG;i>=0;i--){
            if(!(x>>i&1)) continue;
            if(!basis[i]){ basis[i]=x; return; }
            x^=basis[i];
        }
    }
    int getMax(){
        int ans=0;
        for(int i=LOG;i>=0;i--) ans=max(ans,ans^basis[i]);
        return ans;
    }
};
class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        LinearBasis b;
        for(auto x: nums)b.insert(x);
        return b.getMax();
    }
};
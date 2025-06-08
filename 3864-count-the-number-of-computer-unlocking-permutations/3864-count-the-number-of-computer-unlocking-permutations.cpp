class Solution {
public:
    int countPermutations(vector<int>& val) {
        if(*min_element(val.begin()+1,val.end())<=val[0])return 0;
        int n=val.size()-1;
        int m=1e9+7;
        long long ans=1;
        for(int i=1;i<=n;i++)ans=(ans%m*1LL*i)%m;
        return (int)ans;
    }
};
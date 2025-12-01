#define ll long long
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l=0,h=1e14,mid=0;
        ll ans=0;
        while(l<=h){
            mid=l+((h-l)>>1);
            ll rem=0;
            for(auto x: batteries)rem+=min((ll)x,mid);
            if(rem>=mid*n)ans=mid,l=mid+1;
            else h=mid-1;
        }
        return ans;
    }
};
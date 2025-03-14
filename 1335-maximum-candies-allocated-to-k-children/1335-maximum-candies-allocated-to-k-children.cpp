class Solution {
#define allR(v) v.rbegin(),v.rend()
private:
    bool f(vector<int>& candies,long long mid, long long k){
        for(auto x: candies){
            k-=(long long)x/mid;
            if(k<=0)return true;
        }
        return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        sort(allR(candies));
        long long tot=accumulate(allR(candies),(long long)0);
        int n=candies.size();
        if(tot<k)return 0;
        tot/=k;
        long long l=1,h=tot,mid,ans;
        while(l<=h){
            mid=l+(h-l)/2;
            if(f(candies,mid,k)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return (int)ans;
    }
};
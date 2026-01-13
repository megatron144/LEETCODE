class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=1e9;
        while(l<=r){
            int mid=r-(r-l)/2,curr=0;
            for(auto x: piles)curr+=(x+mid-1)/mid;
            if(curr<=h)r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};
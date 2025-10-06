class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> set_bits(31,{n+1,-1});
        vector<int> cnt_bits(31,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<31;j++){
                if((nums[i]>>j)&1)cnt_bits[j]++;
                set_bits[j].first=min(set_bits[j].first,i);
                if(cnt_bits[j]&1)set_bits[j].second=i;
            }
        }
        int mx=0;
        for(auto&[l,r]: set_bits)mx=max({0,mx,r-l+1});
        cnt_bits.assign(31,0);
        set_bits.assign(31,{0,n+1});
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<31;j++){
                if((nums[i]>>j)&1)cnt_bits[j]++;
                set_bits[j].first=max(set_bits[j].first,i);
                if(cnt_bits[j]&1)set_bits[j].second=i;
            }
        }
        for(auto&[l,r]: set_bits)mx=max({0,mx,l-r+1});
        return mx;
    }
};
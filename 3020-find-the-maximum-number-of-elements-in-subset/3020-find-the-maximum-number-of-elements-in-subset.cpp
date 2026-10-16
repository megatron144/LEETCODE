class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> mp;
        for(auto& x: nums)mp[x]++;
        int mx=1;
        if(mp.count(1)){
            int cnt=mp[1];
            mx=max(mx,cnt&1?cnt:cnt-1);
        }
        for(auto &[num,f]: mp){
            if(num==1)continue;
            long long x=num;
            int cnt=0;
            while(mp.count(x) && mp[x]>=2){
                cnt+=2;
                if(x>1e9)break;
                x*=x;
            }
            if(mp.count(x))cnt++;
            else cnt--;
            mx=max(mx,cnt);
        }
        return mx;
    }
};
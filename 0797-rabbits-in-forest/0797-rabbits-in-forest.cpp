class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(auto x: answers)mp[x]++;
        int ans=0;
        for(auto x: mp){
            int val=x.first,cnt=x.second;
            int grp=cnt/(val+1);
            if(cnt%(val+1))grp++;
            ans+=(grp*(val+1));
        }
        return ans;
    }
};
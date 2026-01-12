class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string,long long> mp;
        for(auto x: words){
            string norm=x;
            int shift=norm[0]-'a';
            for(char &c:norm){
                c=(c-'a'-shift+26)%26+'a';
            }
            mp[norm]++;
        }
        long long cnt=0;
        for(auto &p:mp)cnt+=p.second*(p.second-1)/2;
        return cnt;
    }
};
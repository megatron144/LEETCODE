class Solution {
    struct PairHash {
        size_t operator()(const pair<string,string>& p) const {
            return hash<string>()(p.first) ^
                   (hash<string>()(p.second) << 1);
        }
    };
    unordered_map<pair<string,string>,bool,PairHash> mp;
public:
    bool isScramble(string s1, string s2) {
        if(mp.count({s1,s2}))return mp[{s1,s2}];
        if(s1==s2)return true;
        int n=s1.size();
        vector<int> f(26,0);
        for(int i=0;i<n;i++)f[s1[i]-'a']++,f[s2[i]-'a']--;
        for(auto x: f)if(x)return false;
        for(int i=1;i<n;i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) 
                                && isScramble(s1.substr(i),s2.substr(i))){
                                    return mp[{s1,s2}]=true;
                                }
            if(isScramble(s1.substr(0,i),s2.substr(n-i))
                                && isScramble(s1.substr(i),s2.substr(0,n-i))){
                                    return mp[{s1,s2}]=true;
                                }
        }
        return mp[{s1,s2}]=false;
    }
};
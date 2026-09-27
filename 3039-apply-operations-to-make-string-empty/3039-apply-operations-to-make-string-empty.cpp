class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> f(26,0);
        int mx=0;
        for(auto& x: s)f[x-'a']++,mx=max(mx,f[x-'a']);
        int n=s.size();
        string r="";
        for(int i=n-1;i>=0;i--)if(f[s[i]-'a']==mx)r+=s[i],f[s[i]-'a']--;
        reverse(r.begin(),r.end());
        return r;
    }
};
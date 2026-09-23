class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> f(26,0),vis(26,0);
        for(auto& x: s)f[x-'a']++;
        int n=s.size();
        string ans="";
        for(auto& x: s){
            f[x-'a']--;
            if(!vis[x-'a']){
                while(ans.size()>0 && ans.back()>x && f[ans.back()-'a']){
                    vis[ans.back()-'a']=0;
                    ans.pop_back();
                }
                ans+=x;
                vis[x-'a']=1;
            }
        }
        return ans;
    }
};
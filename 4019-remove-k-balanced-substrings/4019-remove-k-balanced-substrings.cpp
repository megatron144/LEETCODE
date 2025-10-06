class Solution {
public:
    string removeSubstring(string s, int k) {
        string ans="";
        for(auto x:s){
            ans.push_back(x);
            int sz=ans.size();
            if(sz>=(2*k)){
                for(int i=0;i<k;i++)if(ans[sz-2*k+i]!='(' || ans[sz-k+i]!=')')goto there;
                ans.resize(sz-2*k);
            }
            there:
        }
        return ans;
    }
};
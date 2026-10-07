class Solution {
private:
    static bool cmp(string& s1,string& s2){
        return s1.length()>s2.length();
    }
    bool isValid(const string& s) {
        int count = 0;
        for(char c : s) {
            if(c=='(')++count;
            if(c==')' && count--==0)return false;
        }
        return count==0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        if (s.empty()) return res;
        unordered_set<string> visited;
        queue<string> q;
        set<string> st;
        q.push(s);
        visited.insert(s);
        while (!q.empty()) {
            s = q.front();
            q.pop();
            if (isValid(s)) {
                st.insert(s);
                continue;
            }
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] != '(' && s[i] != ')') continue;
                
                string t = s.substr(0, i) + s.substr(i + 1);
                
                if (!visited.count(t)) {
                    q.push(t);
                    visited.insert(t);
                }
            }
        }
        auto it=st.begin();
        while(it!=st.end()){
            res.push_back(*it);
            it++;
        }
        sort(res.begin(),res.end(),cmp);
        int len=res[0].length();
        vector<string> ans;
        int i=0;
        while(i<res.size() && len==res[i].length()){
            ans.push_back(res[i]);
            i++;
        }
        return ans;
    }
};
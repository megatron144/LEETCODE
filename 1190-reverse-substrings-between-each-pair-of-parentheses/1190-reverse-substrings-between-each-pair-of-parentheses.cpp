class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int l=st.top();
                st.pop();
                reverse(s.begin()+l,s.begin()+i);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(' || s[i]==')')s.erase(i,1);
        }
        return s;
    }
};
class Solution {
public:
    int scoreOfParentheses(string s) {
        int cnt=0,curr=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                curr++;
            }
            else{
                curr--;
                if(s[i-1]=='(')cnt+=1<<curr;
            }
        }
        return cnt;
    }
};
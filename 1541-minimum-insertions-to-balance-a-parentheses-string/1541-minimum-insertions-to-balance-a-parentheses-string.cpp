class Solution {
public:
    int minInsertions(string s) {
        int cnt=0,curr=0;
        for(int i=0;i<s.size();i++){
            char x=s[i];
            if(x=='('){
                curr+=2;
                if(curr&1)cnt++,curr--;
            }
            else{
                curr--;
                if(curr<0)cnt++,curr=1;
            }
        }
        cnt+=curr;
        return cnt;
    }
};
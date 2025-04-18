class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        while(--n){
            string str="";
            int cnt=1;
            for(int i=1;i<s.length();i++){
                if(s[i]==s[i-1]){
                    cnt++;
                }
                else{
                    string x=to_string(cnt);
                    str+=x;
                    str=str+s[i-1];
                    cnt=1;
                }
            }
            string x=to_string(cnt);
            str+=x;
            str=str+s[s.length()-1];
            cnt=1;
            s=str;
        }
        return s;
    }
};
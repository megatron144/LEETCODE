class Solution {
public:
    int numSteps(string s) {
        int steps=0;
        while(s.length()!=1){
            if(s[s.length()-1]=='1'){
                int pos=s.length()-1;
                while(pos>=0 && s[pos]!='0'){
                    s[pos]='0';
                    pos--;
                }
                if(pos==-1){
                    string str="1";
                    s=str+s;
                }
                else s[pos]='1';
            }
            else{
                int len=s.length()-1;
                s.erase(len,1);
            }
            steps++;
        }
        return steps;
    }
};
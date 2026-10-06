class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0,tmp=0;
        for(auto x: s){
            if(x=='('){
                tmp++;
            }
            else{
                tmp--;
            }
            if(tmp<0){
                cnt-=tmp;
                tmp=0;
            }
        }
        return cnt+abs(tmp);
    }
};
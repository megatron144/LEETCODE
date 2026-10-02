class Solution {
private:
    void f(int op,int cl,string& s,vector<string>& v){
        if(op==0 && cl==0){
            v.push_back(s);
            return;
        }
        if(op>0){
            s=s+'(';
            f(op-1,cl,s,v);
            s.pop_back();
        }
        if(op<cl){
            s=s+')';
            f(op,cl-1,s,v);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s="";
        f(n,n,s,v);
        return v;
    }
};
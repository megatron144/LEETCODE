class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        for(auto s: str){
            if(s=='[' || s=='(' || s=='{')st.push(s);
            else if(st.empty())return 0;
            else{
                if((s==']' && st.top()=='[')||(s==')' && st.top()=='(')||(s=='}' && st.top()=='{'))st.pop();
                else return 0;
            }
        }
        return st.empty()?1:0;
    }
};
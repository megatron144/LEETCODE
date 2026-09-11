class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        int sign='+',n=s.size();
        long long ans=0,curr=0;
        for(int i=0;i<n;i++){
            if(s[i]==' ')continue;
            if(isdigit(s[i]))curr=curr*10+(int)(s[i]-'0');
            else{
                if(sign=='+')st.push(curr);
                else if(sign=='-')st.push(-curr);
                else if(sign=='*'){
                    int top=st.top();
                    st.pop();
                    st.push(curr*top);
                }
                else{
                    int top=st.top();
                    st.pop();
                    st.push(top/curr);
                }
                sign=s[i];
                curr=0;
            }
        }
        if(sign=='+') st.push(curr);
        else if(sign=='-') st.push(-curr);
        else if(sign=='*'){
            long long top=st.top();
            st.pop();
            st.push(curr*top);
        }
        else{
            long long top=st.top();
            st.pop();
            st.push(top/curr);
        }
        while(!st.empty()){
            cout<<st.top()<<" ";
            ans+=st.top();
            st.pop();
        }
        return (int)ans;
    }
};
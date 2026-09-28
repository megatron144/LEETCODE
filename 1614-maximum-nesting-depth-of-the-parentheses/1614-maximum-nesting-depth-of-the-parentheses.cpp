class Solution {
public:
    int maxDepth(string s) {
        int size=0,maxi=INT_MIN;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')size++;
            if(s[i]==')')size--;
            else maxi=max(maxi,size);
        }
        return maxi;
    }
};
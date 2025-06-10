class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0);
        for(char c: s)freq[c-'a']++;
        int m=-1e9,M=1e9;
        for(int f:freq){
            if(f>0){
                if(f%2)m=max(m,f);
                else M=min(M,f);
            }
        }
        return m==-1e9||M==1e9?-1:m-M;
    }
};
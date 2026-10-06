class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        vector<int> v(n+5,0);
        int cnt=0, len=0, j=0;
        char prev='@';
        for(char c: s){
            cnt+=c=='1';
            j+=(prev!=c && c=='0');
            v[j]+=c=='0';
            prev=c;
        }
        int adj2=0;
        for(int i=1; i<j; i++)adj2=max(adj2,v[i]+v[i+1]);
        return cnt+adj2;
    }
};
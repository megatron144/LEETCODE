class Solution {
public:
    long long minSum(vector<int>& a, vector<int>& b) {
        long long s1=0,s2=0;
        int c1=0,c2=0;
        for(auto x: a){
            s1+=x;
            if(!x)c1++;
        }
        for(auto x: b){
            s2+=x;
            if(!x)c2++;
        }
        if(c1 && c2){
            s1+=c1,s2+=c2;
            return max(s1,s2);
        }
        if(c1==0 && c2==0)return (s1==s2)?s1:-1;
        if(c1==0){
            s2+=c2;
            if(s2>s1)return -1;
            return s1;
        }
        s1+=c1;
        if(s1>s2)return -1;
        return s2;
    }
};
class Solution {
#define all(v) v.rbegin(),v.rend()
#define vi vector<int>
#define pb push_back
#define ll long long
public:
    bool hasSameDigits(string s) {
        vi v;
        for(char c: s)
            v.pb(c-'0');
        while(v.size()>2){
            vi t;
            for(int i=1;i<v.size();i++)
                t.pb((v[i-1]+v[i])%10);
            v=t;
        }
        return v[0]==v[1];
    }
};
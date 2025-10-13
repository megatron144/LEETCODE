class Solution {
public:
    int n,mx;
    void solve(string& s,char x,char y){
        int check=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(s[i]==x)check++;
            else if(s[i]==y)check--;
            else{
                mp.clear();
                mp[0]=i;
                check=0;
                continue;
            }
            if(mp.find(check)!=mp.end())mx= max(mx,i-mp[check]);
            else mp[check]=i;
        }
    }
    int longestBalanced(string s) {
        n=s.size(),mx=0;
        int len=1;
        for(int i=1;i<n;i++){
            if(s[i-1]==s[i])len++;
            else{
                mx=max(mx,len);
                len=1;
            }
        }
        mx=max(mx,len);
        solve(s,'a','b');
        solve(s,'b','c');
        solve(s,'a','c');
        map<pair<int,int>,int> mp;
        mp[{0,0}]=-1;
        vector<int> cnt(3,0);
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']++;
            int a=cnt[0]-cnt[1];
            int b=cnt[0]-cnt[2];
            if(mp.find({a,b})!=mp.end())mx=max(mx,i-mp[{a,b}]);
            else mp[{a,b}]=i;
        }
        return mx;
    }
};
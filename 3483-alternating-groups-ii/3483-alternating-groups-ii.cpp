class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int cnt=1,n=colors.size(),last=colors[0];
        vector<int> v;
        for(int i=1;i<n;i++){
            if(last==colors[i]){
                v.push_back(cnt);
                cnt=1;
            }
            else{
                cnt++;
            }
            last=colors[i];
        }
        v.push_back(cnt);
        if(cnt==n && colors[0]!=colors[n-1])return cnt;
        if(colors[n-1]!=colors[0]){
            v[0]+=v[v.size()-1];
            v.pop_back();
        }
        int res=0;
        for(auto x: v){
            if(x>=k){
                res+=x-k+1;
            }
        }
        return res;
    }
};
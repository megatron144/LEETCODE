class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        vector<vector<int>> v(2,vector<int> (7,0));
        int n=t.size();
        vector<int> same(7,0);
        for(int i=0;i<n;i++){
            if(t[i]==b[i]){
                same[t[i]]++;
            }
            else{
                v[0][t[i]]++;
                v[1][b[i]]++;
            }
        }
        int cnt=0,tar=-1;
        for(int i=1;i<7;i++){
            if(same[i])cnt++,tar=i;
        }
        if(cnt>1)return -1;
        if(cnt==1){
            if((v[0][tar]+v[1][tar])!=(n-same[tar]))return -1;
            return min(v[0][tar],v[1][tar]);
        }
        int mini=n;
        for(int i=1;i<7;i++){
            if((v[0][i]+v[1][i])==n)mini=min({mini,v[0][i],v[1][i]});
        }
        return (mini==n)?-1:mini;
    }
};
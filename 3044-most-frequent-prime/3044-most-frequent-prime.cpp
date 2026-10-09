class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        unordered_map<int,int> mp;
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{1,-1},{1,1},{-1,0},{-1,-1},{-1,1}};
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(auto&[x,y]: dir){
                    int nx=x+i,ny=y+j;
                    int curr=mat[i][j];
                    while(nx<m && nx>=0 && ny<n && ny>=0){
                        curr=curr*10+mat[nx][ny];
                        mp[curr]++;
                        nx+=x,ny+=y;
                    }
                }
            }
        }
        int cnt=0,mx=0;
        for(auto& x: mp){
            if(x.first<=10)continue;
            int val=x.first,f=x.second;
            if(f<cnt)continue;
            bool flg=true;
            for(int i=2;i<=(int)sqrt(val);i++){
                if(val%i==0){
                    flg=false;
                    break;
                }
            }
            if(flg){
                if(f==cnt && mx>=val)continue;
                cnt=f,mx=val;
            }
        }
        return !mx?-1:mx;
    }
};
class Solution {
public:
    long long calculateScore(vector<string>& work, vector<int>& val) {
        int n=work.size();
        vector<int> vis(n,0);
        long long ans=0;
        int i=0;
        while(i>-1 && i<n){
            if(vis[i])break;
            vis[i]=1;
            if(work[i]=="jump")i+=val[i];
            else{
                ans+=(long long)val[i];
                i++;
            }
        }
        return ans;
    }
};
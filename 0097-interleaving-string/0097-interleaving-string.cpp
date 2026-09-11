class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(),m=s2.length(),nm=s3.length();
        if(n+m!=nm)return false;
        vector<bool> prev(m+1,false);
        for(int i=0;i<=n;i++){
            vector<bool> curr(m+1,false);
            for(int j=0;j<=m;j++){
                if(!i && !j)curr[j]=true;
                else if(!i)curr[j]=(curr[j-1] && s2[j-1]==s3[i+j-1]);
                else if(!j)curr[j]=(prev[j] && s1[i-1]==s3[i+j-1]);
                else curr[j]=(prev[j] && s1[i-1]==s3[i+j-1]) | 
                                (curr[j-1] && s2[j-1]==s3[i+j-1]);
            }
            prev=curr;
        }
        return prev[m];
    }
};
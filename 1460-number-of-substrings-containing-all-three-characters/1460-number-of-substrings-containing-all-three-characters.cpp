class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        vector<int> v(n);
        int a=-1,b=-1,c=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                v[i]=a;
                a=i;
            }
            else if(s[i]=='b'){
                v[i]=b;
                b=i;
            }
            else{
                v[i]=c;
                c=i;
            }
        }
        
        int maxi=max({a,b,c});
        int ans=0;
        for(int i=0;i<n;i++){
            if(a==-1 || b==-1 || c==-1)break;
            ans+=(n-maxi);
            if(s[i]=='a')a=v[i];
            else if(s[i]=='b')b=v[i];
            else c=v[i];
            maxi=max({a,b,c});
        }
        return ans;
    }
};
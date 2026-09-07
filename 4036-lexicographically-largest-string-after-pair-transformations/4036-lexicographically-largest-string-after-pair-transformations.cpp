class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> res;
        for(auto x: nums){
            string s="";
            while(x){
                if(x&1)s+="1";
                else s+="0";
                x>>=1;
            }
            reverse(s.begin(),s.end());
            //cout<<s<<" ";
            int n=s.length();
            string ans="";
            for(int i=0;i<n;i++){
                if(s[i]=='0')continue;
                int add=n-i-1;
                if(add==26)ans+="zz";
                else ans+=(char)('a'+add);
            }
            res.push_back(ans);
        }
        return res;
    }
};
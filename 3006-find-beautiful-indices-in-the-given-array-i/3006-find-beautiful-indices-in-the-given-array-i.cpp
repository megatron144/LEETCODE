class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n=s.size(),sa=a.size(),sb=b.size();
        vector<int> va,vb;
        for(int i=0;i<=n-sa;i++)if(s.substr(i,sa)==a)va.push_back(i);
        for(int i=0;i<=n-sb;i++)if(s.substr(i,sb)==b)vb.push_back(i);
        vector<int> ans;
        for(auto& x: va){
            auto left=lower_bound(vb.begin(),vb.end(),x-k);
            auto right=upper_bound(vb.begin(),vb.end(),x+k);
            int cnt=distance(left,right);
            if(cnt)ans.push_back(x);
        }
        return ans;
    }
};
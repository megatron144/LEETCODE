class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n=word.size();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i+=k)mp[word.substr(i,k)]++;
        int mx=0;
        for(auto x: mp){
            //cout<<x.first<<" "<<x.second<<endl;
            mx=max(mx,x.second);
        }
        //cout<<mx;
        return n/k-mx;
    }
};
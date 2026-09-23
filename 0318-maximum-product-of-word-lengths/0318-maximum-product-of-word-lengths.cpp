class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<int>> v(26);
        int n=words.size();
        for(int i=0;i<n;i++){
            string x=words[i];
            vector<int> pres(26,0);
            for(auto& ch: x){
                if(!pres[ch-'a'])v[ch-'a'].push_back(i),pres[ch-'a']=1;
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool flg=true;
                for(int k=0;k<26;k++){
                    if(binary_search(v[k].begin(),v[k].end(),i) &&
                            binary_search(v[k].begin(),v[k].end(),j)){
                        flg=false;
                        break;
                    }
                }
                if(flg)mx=max(mx,(int)words[i].size()*(int)words[j].size());
            }
        }
        return mx;
    }
};
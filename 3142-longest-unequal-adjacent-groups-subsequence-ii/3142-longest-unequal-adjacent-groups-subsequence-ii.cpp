class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<int>next(n,-1),len(n,1);
        int res=1,track=0;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(words[i].length()==words[j].length()){
                    int diff=0;
                    for(int k=0;k<words[i].length();k++){
                        if(words[i][k]!=words[j][k]){
                            diff++;
                            if(diff>1)break;
                        }
                    }
                    if(diff==1&&groups[i]!=groups[j]){
                        if(next[i]==-1||len[j]>len[next[i]]){
                            next[i]=j;
                            len[i]=len[j]+1;
                            if(len[i]>res){
                                res=len[i];
                                track=i;
                            }
                        }
                    }
                }
            }
        }
        vector<string> ans;
        while(track!=-1){
            ans.push_back(words[track]);
            track=next[track];
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector<int> ans;
        int c1,c2;
        c1=1,c2=0;
        ans.push_back(1);
        for(int i=1;i<n;i++){
            if(seq[i]=='('){
                if(c1>=c2)ans.push_back(0),c2++;
                else ans.push_back(1),c1++;
            }
            else{
                if(c1>c2)ans.push_back(1),c1--;
                else ans.push_back(0),c2--;
            }
        }
        return ans;
    }
};
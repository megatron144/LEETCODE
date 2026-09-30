class Solution {
public:
    bool isValidSerialization(string preorder) {
        int cnt=1,n=preorder.size();
        for(int i=0;i<n;i++){
            char x=preorder[i];
            if(x==',')continue;
            cnt--;
            if(cnt<0)return false;
            if(x!='#'){
                cnt+=2;
                int j=i+1;
                while(j<n && preorder[j]!=',')j++;
                i=j-1;
            }
        }
        return cnt==0;
    }
};
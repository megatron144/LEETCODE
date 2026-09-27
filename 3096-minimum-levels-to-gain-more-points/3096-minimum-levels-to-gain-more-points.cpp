class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int curr=0,n=possible.size();
        vector<int> post(n);
        for(int i=n-1;i>=0;i--){
            curr+=possible[i]?1:-1;
            post[i]=curr;
        }
        curr=0;
        for(int i=0;i<n-1;i++){
            curr+=possible[i]?1:-1;
            if(!possible[i]){
                if(post[i+1]<curr)return i+1;
                continue;
            }
            if(post[i]-1<curr)return i+1;
        }
        return -1;
    }
};
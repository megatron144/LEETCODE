class Solution {
public:
    int reinitializePermutation(int n) {
        int cnt=0,idx=1;
        do{
            cnt++;
            if(idx<n/2)idx<<=1;
            else idx=(idx<<1)-(n-1);
        }while(idx!=1);
        return cnt;
    }
};
class Solution {
public:
    long long coloredCells(int n) {
        long long ans=0;
        int cnt=n;
        long long add=0;
        while(cnt--){
            ans+=add*2;
            add+=2;
        }
        return ans+1;
    }
};
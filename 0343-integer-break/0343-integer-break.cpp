class Solution {
public:
    int integerBreak(int n) {
        if(n==2 || n==3)return n-1;
        int c3=n/3,r=n%3;
        int mx=(int)pow(3,c3-1);
        if(!r)return 3*mx;
        if(r==1)return mx*4;
        return mx*6;
    }
};
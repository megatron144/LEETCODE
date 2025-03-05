class Solution {
public:
    long long coloredCells(int n) {
        long long ans=(long long)n*(long long)(n-1);
        ans*=2;
        return ans+1;
    }
};
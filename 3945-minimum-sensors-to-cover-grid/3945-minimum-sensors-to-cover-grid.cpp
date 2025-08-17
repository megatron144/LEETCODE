class Solution {
public:
    int minSensors(int n, int m, int k) {
        k=k<<1;
        k++;
        if(n%k)n+=k;
        if(m%k)m+=k;
        return (n/k)*(m/k);
    }
};
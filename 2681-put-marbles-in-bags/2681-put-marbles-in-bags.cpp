class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k == 1) {
            return 0;
        }
        vector<int> v;
        for (int i=0;i<weights.size()-1;i++) {
            v.push_back(weights[i] + weights[i + 1]);
        }
        sort(v.begin(),v.end());
        long long m=accumulate(v.begin(), v.begin()+(k-1),0LL);
        long long M=accumulate(v.end()-(k-1),v.end(),0LL);
        return M-m;
    }
};
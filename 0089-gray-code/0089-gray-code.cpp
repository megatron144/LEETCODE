class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        int m=1<<n;
        for(int i=0;i<m;i++)v.push_back(i^(i>>1));
        return v;
    }
};
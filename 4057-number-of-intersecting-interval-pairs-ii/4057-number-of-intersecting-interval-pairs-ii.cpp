class Solution {
public:
        long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        vector<pair<int, int>> pos;
        for (auto& A : intervals) {
            pos.push_back({A[0], 0});
            pos.push_back({A[1], 1});
        }
        sort(pos.begin(), pos.end());
        long long n = intervals.size();
        long long res = n * (n - 1) / 2;
        long long done = 0;
        for (auto& p : pos) {
            res -= p.second == 0 ? done : 0;
            done += p.second;
        }
        return res;
    }
};
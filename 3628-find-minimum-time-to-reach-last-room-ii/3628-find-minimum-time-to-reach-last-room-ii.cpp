class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        using ll = long long;
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<vector<ll>>> d(2, vector<vector<ll>>(n, vector<ll>(m, 1e18)));
        priority_queue<tuple<ll, int, int, bool>, vector<tuple<ll, int, int, bool>>, greater<>> pq;
        d[0][0][0] = 0;
        pq.push({0, 0, 0, 0});
        int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
        while (!pq.empty()) {
            auto [tm, i, j, mv] = pq.top();
            pq.pop();
            if (tm > d[mv][i][j]) continue;
            if (i == n - 1 && j == m - 1) return tm;

            for (int k = 0; k < 4; ++k) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                ll nt = max(tm, (ll)moveTime[ni][nj]) + (mv ? 2 : 1);
                bool nm = !mv;
                if (nt < d[nm][ni][nj]) {
                    d[nm][ni][nj] = nt;
                    pq.push({nt, ni, nj, nm});
                }
            }
        }
        return -1;
    }
};

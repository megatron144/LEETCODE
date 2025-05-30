class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1);
        int d = 0, curr = node1;
        while (curr != -1 && dist1[curr] == -1) {
            dist1[curr] = d++;
            curr = edges[curr];
        }
        int best = INT_MAX, res = -1;
        vector<bool> seen(n, false);
        d = 0; curr = node2;
        while (curr != -1 && !seen[curr]) {
            seen[curr] = true;
            if (dist1[curr] != -1) {
                int m = max(dist1[curr], d);
                if (m < best || (m == best && curr < res)) {
                    best = m;
                    res = curr;
                }
            }
            d++;
            curr = edges[curr];
        }
        return res;
    }
};
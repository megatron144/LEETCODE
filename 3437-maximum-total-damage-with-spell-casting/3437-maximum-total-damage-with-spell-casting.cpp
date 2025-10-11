class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> damageFrequency;
        for (int pow : power) {
            damageFrequency[pow]++;
        }

        vector<int> uP;
        for (auto x : damageFrequency) {
            uP.push_back(x.first);
        }
        sort(uP.begin(), uP.end());

        int cnt = uP.size();
        if (cnt == 1) {
            return static_cast<long long>(uP[0]) * damageFrequency[uP[0]];
        }

        vector<long long> maxDamage(cnt + 1, 0);
        for (int i = 1; i <= cnt; ++i) {
            long long currentDamage = static_cast<long long>(uP[i - 1]) * damageFrequency[uP[i - 1]];
            long long takeDamage = currentDamage;

            for (int j = i - 2; j >= 0; --j) {
                if (uP[i - 1] - uP[j] > 2) {
                    takeDamage += maxDamage[j + 1];
                    break;
                }
            }

            long long dontTakeDamage = maxDamage[i - 1];
            maxDamage[i] = max(takeDamage, dontTakeDamage);
        }

        return maxDamage[cnt];
    }
};
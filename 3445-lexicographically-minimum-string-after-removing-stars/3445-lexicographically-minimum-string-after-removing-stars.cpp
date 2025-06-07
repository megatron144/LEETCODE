class Solution {
public:
    string clearStars(string s) {
        vector<int> pos[26] = {};
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == '*')
                for (auto &p : pos) {
                    if (!p.empty()) {
                        s[p.back()] = '*';
                        p.pop_back();
                        break;
                    }
                }
            else
                pos[s[i] - 'a'].push_back(i);
        s.erase(remove(begin(s), end(s), '*'), end(s));
        return s;
    }
};
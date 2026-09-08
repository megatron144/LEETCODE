class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;
        unordered_map<string, int> targetFreq;
        for (string& w : words) {
            targetFreq[w]++;
        }
        int n = s.size();
        int wordLen = words[0].length();
        int totalWords = words.size();
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int cnt = 0;
            unordered_map<string, int> windowFreq;
            for (int right = offset; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);
                if (targetFreq.count(word)) {
                    windowFreq[word]++;
                    cnt++;
                    while (windowFreq[word] > targetFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowFreq[leftWord]--;
                        left += wordLen;
                        cnt--;
                    }
                    if (cnt == totalWords) {
                        ans.push_back(left);
                    }
                } 
                else { 
                    windowFreq.clear();
                    cnt = 0;
                    left = right + wordLen;
                }
            }
        }
        return ans;
    }
};
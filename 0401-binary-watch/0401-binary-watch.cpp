class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<vector<string>> hours = {
            {"0"},
            {"1", "2", "4", "8"},
            {"3", "5", "6", "9", "10"},
            {"7", "11"}
        };

        vector<vector<string>> minutes = {
            {"00"},
            {"01", "02", "04", "08", "16", "32"},
            {"03", "05", "06", "09", "10", "12", "17", "18", "20", "24", "33", "34", "36", "40", "48"},
            {"07", "11", "13", "14", "19", "21", "22", "25", "26", "28", "35", "37", "38", "41", "42",
             "44", "49", "50", "52", "56"},
            {"15", "23", "27", "29", "30", "39", "43", "45", "46", "51", "53", "54", "57", "58"},
            {"31", "47", "55", "59"}
        };

        vector<string> result;
        for (int i = 0; i <= min(3, turnedOn); ++i) {
            int j = turnedOn - i;
            if (j > 5) continue;
            for (const auto& hour : hours[i]) {
                for (const auto& minute : minutes[j]) {
                    result.push_back(hour + ":" + minute);
                }
            }
        }

        return result;
    }
};
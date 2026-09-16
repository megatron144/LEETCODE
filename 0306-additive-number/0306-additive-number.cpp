class Solution {
    string add(string a, string b) {
        string res;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';

            res.push_back('0' + sum % 10);
            carry = sum / 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool check(string& s, int pos, string a, string b) {
        int n = s.size();

        if(pos == n)
            return true;

        string sum = add(a, b);

        if(pos + sum.size() > n)
            return false;

        if(s.substr(pos, sum.size()) != sum)
            return false;

        return check(s, pos + sum.size(), b, sum);
    }

public:
    bool isAdditiveNumber(string num) {
        int n = num.size();

        for(int i = 1; i < n; i++) {
            if(i > 1 && num[0] == '0')
                break;
            string a = num.substr(0, i);
            for(int j = i + 1; j < n; j++) {
                if(j - i > 1 && num[i] == '0')
                    break;
                string b = num.substr(i, j - i);
                if(check(num, j, a, b))
                    return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        if (s[0] == '0') {
            return 0;
        }
        int n1 = 1, n2 = 1;
        for (int i = 1; i < s.size(); ++i) {
            int n3;
            if (s[i] == '0') {
                if (s[i-1] > '2' || s[i-1] == '0') return 0;
                n3 = n2;
            } else {
                n3 = n1;
                int num = (s[i-1] - '0') * 10 + s[i] - '0';
                if (num >= 10 && num <= 26)
                    n3 += n2;
            }
            n2 = n1;
            n1 = n3;
        }
        return n1;

    }
};

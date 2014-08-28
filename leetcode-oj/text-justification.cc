#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        if (words.empty()) {
            return result;
        }
        size_t i = 0;
        while (i < words.size()) {
            size_t len = words[i].size();
            size_t j = i + 1;
            while (j < words.size()
                    && len + 1 + words[j].size() <= L) {
                len += 1 + words[j].size();
                ++j;
            }

            result.resize(result.size() + 1);
            string &line = result.back();
            line = words[i];

            if (i + 1 == j) {
                if (line.size() < L) {
                    line.append(L - line.size(), ' ');
                }
            } else {
                int pads = (L - len) / (j - i - 1);
                int leftPads = L - len - pads * (j - i - 1);
                if (j >= words.size()) {
                    pads = 0;
                    leftPads = 0;
                }
                for (int k = i+1; k < j; ++k) {
                    if (leftPads > 0) {
                        line.append(pads + 2, ' ');
                        --leftPads;
                    } else {
                        line.append(pads + 1, ' ');
                    }
                    line += words[k];
                }
                line.append(L - line.size(), ' ');
            }
            i = j;
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    int L = atoi(argv[1]);
    vector<string> words;
    for (int i = 2; i < argc; ++i) {
        words.push_back(string(argv[i]));
    }
    Solution s;
    vector<string> result = s.fullJustify(words, L);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << '$' << endl;
    }
    return 0;
}

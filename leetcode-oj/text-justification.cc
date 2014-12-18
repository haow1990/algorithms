#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int i = 0;
        while (i < words.size()) {
            // will pack words[i..j] to a new line
            int j = i;
            int totalsize = words[i].size();
            while (j + 1 < words.size() && totalsize + 1 + words[j+1].size() <= L) {
                ++j;
                totalsize = totalsize + 1 + words[j].size();
            }
            res.push_back(words[i]);
            if (i == j) {
                res.back().append(L - totalsize, ' ');
            } else if (j + 1 == words.size()) {
                for (int k = i + 1; k <= j; ++k) {
                    res.back().append(1, ' ');
                    res.back() += words[k];
                }
                res.back().append(L - totalsize, ' ');
            } else {
                int per = (L - totalsize) / (j - i);
                int spacesleft = L - totalsize - per * (j - i);
                for (int k = i + 1; k <= j; ++k) {
                    if (spacesleft > 0) {
                        res.back().append(per + 2, ' ');
                        --spacesleft;
                    } else {
                        res.back().append(per + 1, ' ');
                    }
                    res.back() += words[k];
                }
            }
            
            i = j + 1;
        }
        return res;
    
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

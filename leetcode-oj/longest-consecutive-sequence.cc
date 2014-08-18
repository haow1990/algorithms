#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> nset;
        for (size_t i = 0; i < num.size(); ++i) {
            nset.insert(num[i]);
        }
        int max = 0;
        while (nset.empty() == false) {
            int current = *nset.begin();
            nset.erase(nset.begin());
            int count = 1;

            int inc = current;
            while (true) {
                ++inc;
                unordered_set<int>::iterator iter = nset.find(inc);
                if (iter != nset.end()) {
                    ++count;
                    nset.erase(iter);
                } else {
                    break;
                }
            }

            int dec = current;
            while (true) {
                --dec;
                unordered_set<int>::iterator iter = nset.find(dec);
                if (iter != nset.end()) {
                    ++count;
                    nset.erase(iter);
                } else {
                    break;
                }
            }

            if (count > max)
                max = count;
        }

        return max;
    }
};

int main(int argc, char **argv)
{
    vector<int> vec;
    for (int i = 1; i < argc; ++i) {
        vec.push_back(atoi(argv[i]));
    }
    Solution s;
    cout << s.longestConsecutive(vec) << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        const size_t DIM = s.size();
        bool *array = new bool[DIM * DIM];
        string tmp;
        for (size_t step = 1; step <= DIM; ++step) {
            for (size_t start = 0; start <= DIM - step; ++start) {
                tmp.assign(s, start, step);
                size_t end = start + step;
                array[DIM * start + end - 1] = false;
                if (dict.count(tmp) > 0) {
                    array[DIM * start + end - 1] = true;
                } else {
                    for (size_t i = start + 1; i < end; ++i) {
                        if (array[DIM * start + i - 1] && array[DIM * i + end - 1]) {
                            array[DIM * start + end - 1] = true;
                            break;
                        }
                    }
                }
            }
        }
        bool result = array[0 + DIM - 1];
        delete array;
        return result;
    }
};

int main()
{
    string s = "leetcodeleet";
    unordered_set<string> voc;
    voc.insert("leet");
    voc.insert("code");
    Solution ss;
    cout << ss.wordBreak(s, voc) << endl;
    return 0;
}

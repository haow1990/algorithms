#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty()) {
            return intervals;
        }
        auto cmp = [](Interval v1, Interval v2) {
            if (v1.start < v2.start) {
                return true;
            } else if (v1.start > v2.start) {
                return false;
            } else {
                return v1.end < v2.end;
            }
        };
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        res.push_back(intervals.front());
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start > res.back().end) {
                res.push_back(intervals[i]);
            } else {
                res.back().end = max(res.back().end, intervals[i].end);
            }
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    vector<Interval> intervals;
    for (int i = 1; i + 1 < argc; i += 2) {
        intervals.push_back(Interval(atoi(argv[i]), atoi(argv[i+1])));
    }
    Solution s;
    vector<Interval> out = s.merge(intervals);
    for (size_t i = 0; i < out.size(); ++i) {
        cout << '(' << out[i].start << ',' << out[i].end << ") ";
    }
    cout << endl;
    return 0;
}

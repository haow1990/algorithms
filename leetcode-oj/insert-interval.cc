#include <cstdlib>
#include <iostream>
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        auto iter = intervals.begin();
        while (iter != intervals.end() && iter->start <= newInterval.start) {
            res.push_back(*iter);
            ++iter;
        }
        if (res.empty() || res.back().end < newInterval.start) {
            res.push_back(newInterval);
        } else {
            res.back().end = max(res.back().end, newInterval.end);
        }
        while (iter != intervals.end() && iter->start <= res.back().end) {
            res.back().end = max(res.back().end, iter->end);
            ++iter;
        }
        while (iter != intervals.end()) {
            res.push_back(*iter);
            ++iter;
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    Interval newInterval(atoi(argv[1]), atoi(argv[2]));
    vector<Interval> intervals;
    for (int i = 3; i + 1 < argc; i += 2) {
        intervals.push_back(Interval(atoi(argv[i]), atoi(argv[i+1])));
    }
    Solution s;
    vector<Interval> out = s.insert(intervals, newInterval);
    for (size_t i = 0; i < out.size(); ++i) {
        cout << '(' << out[i].start << ',' << out[i].end << ") ";
    }
    cout << endl;
    return 0;
}

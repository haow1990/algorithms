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
        vector<Interval> result;
        size_t i = 0;
        while (i < intervals.size() && intervals[i].end < newInterval.start) {
            result.push_back(intervals[i]);
            ++i;
        }
        result.push_back(newInterval);
        while (i < intervals.size()
                && result.back().end >= intervals[i].start
                && result.back().start <= intervals[i].end) {
            if (intervals[i].start < result.back().start) {
                result.back().start = intervals[i].start;
            }
            if (intervals[i].end > result.back().end) {
                result.back().end = intervals[i].end;
            }
            ++i;
        }
        while (i < intervals.size()) {
            result.push_back(intervals[i]);
            ++i;
        }
        return result;
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

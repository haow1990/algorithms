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

bool operator<(const Interval &a, const Interval &b)
{
    return a.start > b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty()) {
            return intervals;
        }
        priority_queue<Interval> q;
        for (auto &iter : intervals) {
            q.push(iter);
        }
        vector<Interval> result;
        result.push_back(q.top());
        q.pop();
        while (q.empty() == false) {
            if (result.back().end >= q.top().start
                    && result.back().start <= q.top().end) {
                if (q.top().start < result.back().start) {
                    result.back().start = q.top().start;
                }
                if (q.top().end > result.back().end) {
                    result.back().end = q.top().end;
                }
            } else {
                result.push_back(q.top());
            }
            q.pop();
        }
        return result;
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

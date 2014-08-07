#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct line {
    int a, b, c;
    line(int aa = 0, int bb = 0, int cc = 0)
        : a(aa), b(bb), c(cc)
    {}

    size_t hash() const
    {
        if (c != 0) {
            return a * a / (c * c) + b * b / (c * c);
        } else if (b != 0) {
            return a * a / (b * b);
        } else {
            return 0;
        }
    }
};

bool operator==(const line &l1, const line &l2)
{
    return l1.a * l2.c == l2.a * l1.c &&
           l1.b * l2.c == l2.b * l1.c &&
           l1.a * l2.b == l2.a * l1.b;
}

struct linehash
{
    size_t operator()(const line &ll)const
    {
        return ll.hash();
    }
};

struct Point
{
    int x;
    int y;
    Point(int a = 0, int b = 0)
        : x(a), y(b)
    {}
};

class Solution
{
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() < 3) {
            return points.size();
        }
        int max = 0;
        for (int i = 0; i < points.size(); ++i) {
            const Point &p1 = points[i];
            unordered_map<line, int, linehash> mm;
            int identical = 0;
            for (int j = i + 1; j < points.size(); ++j) {
                const Point &p2 = points[j];
                if (p2.x == p1.x && p2.y == p1.y) {
                    identical += 1;
                    continue;
                }
                int a = p2.y - p1.y;
                int b = p1.x - p2.x;
                int c = 0 - a * p1.x - b * p1.y;
                line ll(a, b, c);
                unordered_map<line, int, linehash>::iterator iter = mm.find(ll);
                if (iter != mm.end()) {
                    iter->second += 1;
                } else {
                    mm[ll] = 1;
                }
            }

            if (max < identical + 1) {
                max = identical + 1;
            }
            for (unordered_map<line, int, linehash>::iterator iter = mm.begin();
                    iter != mm.end(); ++iter) {
                if (max < iter->second + identical + 1) {
                    max = iter->second + identical + 1;
                }
            }
        }

        return max;
    }
};

int main(int argc, char **argv)
{
    vector<Point> points;
    points.push_back(Point(0, 0));
    points.push_back(Point(0, 0));
    points.push_back(Point(0, 0));
    points.push_back(Point(0, 1));
    points.push_back(Point(1, 1));

    Solution s;
    cout << "max is: " << s.maxPoints(points) << endl;
    return 0;
}


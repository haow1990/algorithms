/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
 struct line {
     int a, b, c;
     line(int aa, int bb, int cc)
        : a(aa), b(bb), c(cc)
     {}
     line(Point p1, Point p2) {
         a = p2.y - p1.y;
         b = p1.x - p2.x;
         c = -a * p1.x - b * p1.y;
     }
 };
 
 struct linehash {
     size_t operator()(const line &ll) const {
         if (ll.c != 0) {
             int c2 = ll.c * ll.c;
             return ll.a * ll.a / c2 + ll.b * ll.b / c2;
         } else if (ll.b != 0) {
             return ll.a * ll.a / ll.b / ll.b;
         } else {
             return 0;
         }
     }
 };
 
 bool operator==(const line &l1, const line &l2) {
     return l1.a * l2.b == l1.b * l2.a
            && l1.a * l2.c == l1.c * l2.a
            && l1.b * l2.c == l1.c * l2.b;
 }
 
 bool operator==(const Point &p1, const Point &p2) {
     return p1.x == p2.x && p1.y == p2.y;
 }
 
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() < 3) {
            return points.size();
        }
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            int same = 1;
            unordered_map<line, int, linehash> lines;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i] == points[j]) {
                    ++same;
                    continue;
                }
                ++lines[line(points[i], points[j])];
            }
            int cur = 0;
            for (auto &pr : lines) {
                cur = max(cur, pr.second);
            }
            res = max(res, cur + same);
        }
        return res;
    }
};





#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result("1");
        string tmp;
        while (n > 1) {
            tmp.clear();
            int i = 0;
            while (i < result.size()) {
                int count = 0;
                char val = result[i];
                while (i < result.size() && result[i] == val) {
                    ++count;
                    ++i;
                }
                char buf[64];
                int c = snprintf(buf, 64, "%d", count);
                tmp.append(buf, c);
                tmp.push_back(val);
            }
            result.swap(tmp);
            --n;
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    Solution s;
    cout << s.countAndSay(n) << endl;
    return 0;
}

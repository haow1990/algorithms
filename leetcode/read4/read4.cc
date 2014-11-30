#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

const int SIZE = 4;

class Solution {
private:
    const int total;
    int current;
    unsigned char data[SIZE];
    int start;
    int end;
public:
    Solution(int tt)
        : total(tt), current(0), start(0), end(0)
    {}
    
    int read4(unsigned char *buf)
    {
        int res = 0;
        while (res < SIZE && current < total) {
            buf[res++] = current++;
        }
        return res;
    }

    int read(unsigned char *buf, int n)
    {
        if (n <= end - start) {
            memcpy(buf, data + start, n);
            start += n;
            return n;
        } else {
            memcpy(buf, data + start, end - start);
            int res = end - start;
            start = end;
            while (res + SIZE <= n) {
                int cnt = read4(buf + res);
                res += cnt;
                if (cnt < SIZE) {
                    return res;
                }
            }
            if (res < n) {
                end = read4(data);
                start = min(n - res, end);
                memcpy(buf + res, data, start);
                res += start;
            }
            return res;
        }
    }
};

bool test1(int total, int requested)
{
    Solution s(total);
    unsigned char buf[requested];
    int cnt = s.read(buf, requested);
    if (cnt != min(total, requested)) {
        return false;
    }
    for (int i = 0; i < cnt; ++i) {
        if (buf[i] != (i % 256)) {
            return false;
        }
    }
    return true;
}

bool test2(int total, int requested, int first)
{
    Solution s(total);
    unsigned char buf[requested];
    int cnt1 = s.read(buf, first);
    if (cnt1 != min(first, total)) {
        return false;
    }
    int cnt2 = s.read(buf + cnt1, requested - cnt1);
    if (cnt1 + cnt2 != min(total, requested)) {
        return false;
    }
    for (int i = 0; i < cnt1 + cnt2; ++i) {
        if (buf[i] != (i % 256)) {
            return false;
        }
    }
    return true;

}

int main(int argc, char **argv)
{
    bool showgood = argc > 1;
    for (int i = 0; i <= 300; ++i) {
        for (int j = 0; j <= 300; ++j) {
            if (test1(i, j) == false) {
                cout << "FAILED: " << i << ", " << j << endl;
            } else if (showgood) {
                cout << "GOOD: " << i << ", " << j << endl;
            }
        }
    }
    for (int i = 0; i <= 300; ++i) {
        for (int j = 0; j <= 300; ++j) {
            for (int k = 0; k <=j; ++k) {
                if (test2(i, j, k) == false) {
                    cout << "FAILED2: " << i << ", " << j << ", " << k << endl;
                } else if (showgood) {
                    cout << "GOOD2: " << i << ", " << j << ", " << k << endl;
                }
            }
        }
    }
    return 0;
}


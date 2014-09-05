#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void swap(vector<int> &num, int i, int j)
    {
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
    }
    
    void nextPermutation(vector<int> &num) {
        if (num.size() < 2) {
            return;
        }
        int last = num.size() - 1;
        if (num[last] > num[last-1]) {
            swap(num, last, last-1);
            return;
        }
        int peak = last - 1;
        while (peak > 0 && num[peak] <= num[peak-1]) {
            --peak;
        }
        reverse(num.begin() + peak, num.end());
        if (peak > 0) {
            int j = last;
            while (j >= peak && num[peak-1] < num[j]) {
                --j;
            }
            swap(num, j + 1, peak - 1);
        }
    }
};

int main(int argc, char **argv)
{
    vector<int> num;
    for (int i = 1; i < argc; ++i) {
        num.push_back(atoi(argv[i]));
    }
    for (int n : num) {
        cout << n << ' ';
    }
    cout << endl;

    Solution s;
    s.nextPermutation(num);
    for (int n : num) {
        cout << n << ' ';
    }
    cout << endl;
    return 0;
}

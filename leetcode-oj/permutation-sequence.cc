#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int FACTORIALS[] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

class Solution {
public:
    vector<int> numbers;
    string current;
    void doPerm(int n, int k)
    {
        if (n == 1) {
            current.push_back('0' + numbers[0]);
            return;
        }
        int idx = k / FACTORIALS[n-1];
        current.push_back('0' + numbers[idx]);
        numbers.erase(numbers.begin() + idx);
        doPerm(n - 1, k % FACTORIALS[n-1]);
    }

    string getPermutation(int n, int k) {
        numbers.resize(n);
        for (int i = 0; i < n; ++i) {
            numbers[i] = i + 1;
        }
        current.clear();
        doPerm(n, k-1);
        return current;
    }
};

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    Solution s;
    cout << s.getPermutation(n, k) << endl;
    return 0;
}

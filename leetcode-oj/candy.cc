#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.size() < 2) {
            return ratings.size();
        }
        int count = 1;
        int lastCandy = 1;
        int declen = 0;
        int beforeDec = 1;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] < ratings[i-1]) {
                declen += 1;
                if (declen >= beforeDec) {
                    ++count;
                }
                count += declen;
                lastCandy = 1;
            } else {
                if (ratings[i] == ratings[i-1]) {
                    lastCandy = 1;
                } else {
                    ++lastCandy;
                }
                count += lastCandy;
                beforeDec = lastCandy;
                declen = 0;
            }
        }
        return count;
    }

};

int main(int argc, char **argv)
{
    vector<int> vec;
    for (int i = 1; i < argc; ++i) {
        vec.push_back(atoi(argv[i]));
    }
    Solution s;
    cout << s.candy(vec) << endl;
    return 0;
}


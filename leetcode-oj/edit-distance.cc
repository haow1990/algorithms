#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > array(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 0; i <= word1.size(); ++i) {
            array[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); ++j) {
            array[0][j] = j;
        }
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                int add = array[i][j-1] + 1;
                int del = array[i-1][j] + 1;
                int rep = array[i-1][j-1];
                if (word1[i-1] != word2[j-1]) {
                    ++rep;
                }
                int min = add;
                if (min > del)  min = del;
                if (min > rep)  min = rep;
                array[i][j] = min;
            }
        }
        return array[word1.size()][word2.size()];
    }
};

int main(int argc, char **argv)
{
    string word1(argv[1]);
    string word2(argv[2]);
    Solution s;
    cout << s.minDistance(word1, word2) << endl;
    return 0;
}

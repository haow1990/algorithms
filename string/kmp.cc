#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> calculateNext(const string &p)
{
    vector<int> next(p.size());
    next[0] = -1;
    int plen = p.size();
    int k = -1, j = 0;
    while (j < plen - 1) {
        if (k == -1 || p[j] == p[k]) {
            ++j;
            ++k;
            if (p[j] != p[k]) {
                next[j] = k;
            } else {
                next[j] = next[k];
            }
        } else {
            k = next[k];
        }
    }
    return next;
}

int strstr(const string &str, const string &ptn)
{
    if (ptn.empty()) {
        return 0;
    }
    vector<int> next = calculateNext(ptn);
    int slen = str.size();
    int plen = ptn.size();
    int i = 0, j = 0;
    while (i < slen && j < plen) {
        if (j == -1 || str[i] == ptn[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j == ptn.size()) {
        return i - j;
    } else {
        return -1;
    }
}

int main(int argc, char **argv)
{
    string str(argv[1]);
    string ptn(argv[2]);
    cout << str << endl;
    int i = strstr(str, ptn);
    if (0 <= i && i < str.size()) {
        for (int j = 0; j < i; ++j) {
            cout << ' ';
        }
        cout << "^\n";
    }
    return 0;
}


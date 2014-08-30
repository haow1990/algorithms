#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

struct smeta {
    size_t len;
    long sum;
    long sum2;
    long product;
    
    smeta(size_t lval, long sval, long pval)
        : len(lval), sum(sval), sum2(0), product(pval)
    {}

    smeta(const string &str)
    {
        len = str.size();
        sum = 0;
        sum2 = 0;
        product = 1;
        for (char c : str) {
            sum += c - 'a' + 1;
            sum2 += (c - 'a' + 1) * (c - 'a' + 1);
            product *= c - 'a' + 1;
        }
    }
};

bool operator==(const smeta &sm1, const smeta &sm2)
{
    return sm1.len == sm2.len
        && sm1.sum == sm2.sum
        && sm1.sum2 == sm2.sum2
        && sm1.product == sm2.product;
}

struct smhash
{
    size_t operator()(const smeta &sm) const
    {
        return sm.len * sm.sum * sm.sum2 * sm.product;
    }
};

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        unordered_map<smeta, vector<const string*>, smhash> metas;
        for (const string &str : strs) {
            smeta meta(str);
            auto iter = metas.find(meta);
            if (iter == metas.end()) {
                iter = metas.insert(make_pair(meta, vector<const string *>())).first;
            }
            iter->second.push_back(&str);
        }
        for (auto &kvp : metas) {
            if (kvp.second.size() <= 1) {
                continue;
            }
            for (auto strp : kvp.second) {
                result.push_back(*strp);
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    vector<string> strs;
    for (int i = 1; i < argc; ++i) {
        strs.push_back(argv[i]);
    }
    Solution s;
    vector<string> result = s.anagrams(strs);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}



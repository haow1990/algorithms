class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.empty()) {
            return 0;
        }
        int res = num[0];
        int i = 0, j = num.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            res = min(res, num[mid]);
            while (i < mid && num[i] == num[mid]) {
                ++i;
            }
            while (j > mid && num[j] == num[mid]) {
                --j;
            }
            if (num[i] <= num[mid]) {
                res = min(res, num[i]);
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return res;
    }
};
